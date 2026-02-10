#pragma once

#include <Arduino.h>
#include "SOLive.h"

class SOLive_C22 {
public:
    static void send(
        SOLive& so,
        int total_runs,
        int wickets,
        float overs,
        int first_inns,
        const char* bat_1_name,
        int bat_1_score,
        const char* bat_2_name,
        int bat_2_score,
        int dls_par
    );
};
