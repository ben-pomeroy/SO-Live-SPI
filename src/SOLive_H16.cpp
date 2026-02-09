#include "SOLive_H16.h"

void SOLive_H16::send(
  SOLive& so,
  const char* homeName,
  const char* awayName,
  int homeScore,
  int awayScore,
  int period,
  String timeStr
) {
  String json =
    String("{\"home_name\":\"") + SOLive::nameForJson(homeName) +
    "\",\"away_name\":\"" + SOLive::nameForJson(awayName) +
    "\",\"home_score\":" + homeScore +
    ",\"away_score\":" + awayScore +
    ",\"period\":" + period +
    ",\"time\":\"" + timeStr +
    "\",\"scoreboard_type\":\"H16\"}";

  so.sendJsonRaw(json.c_str());
}
