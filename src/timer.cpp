#include "timer.hpp"
using namespace std::chrono;

Timer::Timer() : running(false), hasStopped(false) {}

void Timer::start() {
    running = true;
    hasStopped = false;
    startTime = steady_clock::now();
}

void Timer::stop() {
    if (running) {
        endTime = steady_clock::now();
        running = false;
        hasStopped = true;
    }
}

int Timer::elapsed() const {
    if (running) {
        time_point<steady_clock> now = steady_clock::now();
        seconds elapsedTime = duration_cast<seconds>(now - startTime);
        return static_cast<int>(elapsedTime.count());
    } else if (hasStopped) {
       seconds elapsedTime = duration_cast<seconds>(endTime - startTime);
        return static_cast<int>(elapsedTime.count());
    } else {
        return 0;
    }
}
