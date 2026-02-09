#pragma once
#include "SOLive.h"

class SOLive_ProTimer {
public:
  static void send(
    SOLive& so,
    const char* homeName,
    const char* awayName,
    String timeStr,
    int homeScore,
    int awayScore
  );
};
