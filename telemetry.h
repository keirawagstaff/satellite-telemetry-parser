#pragma once
#include <string>

struct TelemetryRecord {
    int time_stamp;
    double temperature_C;
    double battery_pct;
    double altitude_km;
    double signal_strength;
};