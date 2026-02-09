#include "SOLive.h"
#include "SOLive_Protocol.h"

SOLive::SOLive(uint8_t csPin) : _csPin(csPin) {}

void SOLive::begin() {
  pinMode(_csPin, OUTPUT);
  digitalWrite(_csPin, HIGH);
  SPI.begin();
}

void SOLive::setJsonFlag() {
  _lastChangeMs = millis();
}

String SOLive::nameForJson(const char* nameBuf) {
  String out;

  for (int i = 0; i < 14; i++) {
    uint8_t c = (uint8_t)nameBuf[i];
    if (c == 0xFF || c == '_' || c == 0x00) continue;
    if (c < 32 || c > 126) continue;
    out += (char)c;
  }

  out.trim();
  return out;
}

bool SOLive::quietElapsed(uint32_t quietTimeMs) const {
  return millis() - _lastChangeMs >= quietTimeMs;
}

uint16_t SOLive::crc16_ccitt(const uint8_t *data, size_t len) {
  uint16_t crc = 0xFFFF;
  while (len--) {
    crc ^= (uint16_t)(*data++) << 8;
    for (uint8_t i = 0; i < 8; i++) {
      crc = (crc & 0x8000) ? (crc << 1) ^ 0x1021 : (crc << 1);
    }
  }
  return crc;
}

void SOLive::sendPacket(const uint8_t* buf) {
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  digitalWrite(_csPin, LOW);

  uint8_t dummyRx[SOLIVE_MAX_PACKET];
  for (int i = 0; i < SOLIVE_MAX_PACKET; i++) {
    dummyRx[i] = SPI.transfer(buf[i]);
  }

  digitalWrite(_csPin, HIGH);
  SPI.endTransaction();

  delayMicroseconds(1500);
}

void SOLive::sendJsonRaw(const char* json) {
  int len = strlen(json);
  int chunk = 0;

  uint16_t crc = crc16_ccitt((const uint8_t*)json, len);

  while (len > 0) {
    uint8_t buf[SOLIVE_MAX_PACKET] = {0};

    int send_len = min((int)SOLIVE_MAX_PAYLOAD, len);

    buf[0] = SOLIVE_CMD_CHUNK;
    buf[1] = chunk & 0xFF;
    buf[2] = send_len;

    memcpy(&buf[3], json, send_len);
    sendPacket(buf);

    json += send_len;
    len -= send_len;
    chunk++;
  }

  uint8_t endbuf[SOLIVE_MAX_PACKET] = {0};
  endbuf[0] = SOLIVE_CMD_END;
  endbuf[1] = chunk & 0xFF;
  endbuf[2] = (chunk >> 8) & 0xFF;
  endbuf[3] = crc & 0xFF;
  endbuf[4] = (crc >> 8) & 0xFF;

  sendPacket(endbuf);
}
