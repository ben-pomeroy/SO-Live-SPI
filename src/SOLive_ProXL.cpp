#include "SOLive_ProXL.h"

void SOLive_ProXL::send(
  SOLive& so,
  const char* homeName,
  const char* awayName,
  String timeStr,
  int homeScore,
  int awayScore
) {
  String json =
    String("{\"home_name\":\"") + SOLive::nameForJson(homeName) +
    "\",\"away_name\":\"" + SOLive::nameForJson(awayName) +
    "\",\"time\":\"" + timeStr +
    "\",\"home_score\":" + homeScore +
    ",\"away_score\":" + awayScore +
    ",\"scoreboard_type\":\"Pro-Timer\"}";

  so.sendJsonRaw(json.c_str());
}
