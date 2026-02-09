#include "SOLive_C16.h"

void SOLive_C16::send(
    SOLive& so,
    int total_runs,
    int wickets,
    float overs,
    int first_inns,
    int bat_1_score,
    int bat_2_score
) {
    String json =
        String("{\"total_runs\":") + total_runs +
        ",\"wickets\":" + wickets +
        ",\"overs\":" + String(overs, 1) +
        ",\"first_inns\":" + first_inns +
        ",\"bat_1_score\":" + bat_1_score +
        ",\"bat_2_score\":" + bat_2_score +
        ",\"scoreboard_type\":\"C16\"}";

    so.sendJsonRaw(json.c_str());
}
