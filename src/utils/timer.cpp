#include "timer.hpp"

timer::timer()
        : start(clock::now()) {
}

size_t timer::passed_time(unit unit) {
    time_duration duration = clock::now() - start;
    switch (unit) {
        case NANOSECOND:
            return duration.count();
        case MICROSECOND:
            return duration_cast<std::chrono::microseconds>(duration).count();
        case MILLISECOND:
            return duration_cast<std::chrono::milliseconds>(duration).count();
        case SECOND:
            return duration_cast<std::chrono::seconds>(duration).count();
        case MINUTE:
            return duration_cast<std::chrono::minutes>(duration).count();
    }
}
