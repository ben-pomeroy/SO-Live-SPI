#pragma once

#include <Arduino.h>
#include "SOLive.h"

class SOLive_C9 {
public:
    static void send(
        SOLive& so,
        int total_runs,
        int wickets,
        float overs,
        int first_inns
    );
};
