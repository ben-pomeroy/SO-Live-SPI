#pragma once

#include <Arduino.h>
#include "SOLive.h"

class SOLive_C16 {
public:
    void send(
        SOLive& so,
        int total_runs,
        int wickets,
        float overs,
        int first_inns,
        int bat_1_score,
        int bat_2_score
    );
};
