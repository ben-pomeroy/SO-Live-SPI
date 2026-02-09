#include "SOLive_C29.h"

void SOLive_C29::send(
    SOLive& so,
    int total_runs,
    int wickets,
    float overs,
    int first_inns,
    const char* bat_1_name,
    int bat_1_score,
    const char* bat_2_name,
    int bat_2_score,
    int dls_par,
    int last_man,
    int last_wkt
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
        ",\"dls_par\":" + dls_par +
        ",\"last_man\":" + last_man +
        ",\"last_wkt\":" + last_wkt +
        ",\"scoreboard_type\":\"C29\"}";

    so.sendJsonRaw(json.c_str());
}
