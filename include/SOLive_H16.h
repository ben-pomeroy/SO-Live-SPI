#pragma once
#include "SOLive.h"

class SOLive_H16 {
public:
  static void send(
    SOLive& so,
    const char* homeName,
    const char* awayName,
    int homeScore,
    int awayScore,
    int period,
    String timeStr
  );
};
