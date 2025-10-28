#include <chrono> //measure time!
using namespace std::chrono;

class Timer {
private:
    time_point<steady_clock> startTime;
    time_point<steady_clock> endTime;
    bool running;
    bool hasStopped;

public:
    Timer();           // Constructor
    void start();      // Start the timer
    void stop();       // Stop the timer
    int elapsed() const; // Return elapsed time in whole seconds
};
