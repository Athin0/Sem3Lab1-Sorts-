//
// Created by arina on 02.10.2021.
//

#ifndef SORTS_TIMER_H
#define SORTS_TIMER_H
#include <chrono>

class Timer {
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<clock_t> _time;
public:
    Timer(): _time(clock_t::now()) {}

    void Start() {
        _time = clock_t::now();
    }

    double Time() {
        return std::chrono::duration_cast<second_t>(clock_t::now() - _time).count() *1000;
    }
};

#endif //SORTS_TIMER_H
