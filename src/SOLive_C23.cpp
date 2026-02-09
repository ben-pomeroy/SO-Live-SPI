#include "SOLive_C23.h"

void SOLive_C23::send(
    SOLive& so,
    int total_runs,
    int wickets,
    float overs,
    int first_inns,
    const char* bat_1_name,
    int bat_1_score,
    const char* bat_2_name,
    int bat_2_score
) {
    String json =
        String("{\"total_runs\":") + total_runs +
        ",\"wickets\":" + wickets +
        ",\"overs\":" + String(overs, 1) +
        ",\"first_inns\":" + first_inns +
        ",\"bat_1_name\":\"" + SOLive::nameForJson(bat_1_name) +
        "\",\"bat_1_score\":" + bat_1_score +
        ",\"bat_2_name\":\"" + SOLive::nameForJson(bat_2_name) +
        "\",\"bat_2_score\":" + bat_2_score +
        ",\"scoreboard_type\":\"C22\"}";

    so.sendJsonRaw(json.c_str());
}
