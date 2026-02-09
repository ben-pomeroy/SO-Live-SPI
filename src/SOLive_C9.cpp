#include "SOLive_C9.h"

void SOLive_C9::send(
    SOLive& so,
    int total_runs,
    int wickets,
    float overs,
    int first_inns
) {
    String json =
        String("{\"total_runs\":") + total_runs +
        ",\"wickets\":" + wickets +
        ",\"overs\":" + String(overs, 1) +
        ",\"first_inns\":" + first_inns +
        ",\"scoreboard_type\":\"C9\"}";

    so.sendJsonRaw(json.c_str());
}
