#pragma once
#include <Arduino.h>
#include <SPI.h>

class SOLive {
public:
  SOLive(uint8_t csPin);

  void begin();
  void setJsonFlag();

  // core helpers
  static String nameForJson(const char* nameBuf);
  static uint16_t crc16_ccitt(const uint8_t *data, size_t len);
  bool quietElapsed(uint32_t quietTimeMs) const;

  // raw JSON sender (used by board-specific helpers)
  void sendJsonRaw(const char* json);

private:
  uint8_t _csPin;
  uint32_t _lastChangeMs;

  void sendPacket(const uint8_t* buf);
};
