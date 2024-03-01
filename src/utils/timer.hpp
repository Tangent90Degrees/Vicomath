#pragma once

#include <chrono>

enum time_unit {
    NANOSECOND,
    MICROSECOND,
    MILLISECOND,
    SECOND,
    MINUTE
};

class timer {
public:
    typedef std::chrono::high_resolution_clock clock;
    typedef clock::time_point time_point;
    typedef std::chrono::nanoseconds time_duration;
    typedef time_unit unit;

    timer();

    size_t passed_time(unit unit);

private:
    time_point start;
};