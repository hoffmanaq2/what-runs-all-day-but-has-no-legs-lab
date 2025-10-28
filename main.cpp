#include <iostream>
#include "src/timer.hpp"
#include <thread> //for "sleep_for"
#include <ctime>
using namespace std;

void printSystemTime() {
    // Get current system time
    system_clock::time_point currentTime = system_clock::now();

    // Convert to time_t (a C-style time type)
    time_t timeNow = system_clock::to_time_t(currentTime);

    // Convert to readable string
    cout << "System time: " << ctime(&timeNow);
}

int main() {
    cout << "Testing Timer class..." << endl;

    Timer timer;

    cout << "Getting system time before starting timer:\n";
    printSystemTime();

    cout << "\nStarting timer for 3 seconds..." << endl;
    timer.start();

    this_thread::sleep_for(seconds(3)); // Wait 3 seconds

    timer.stop();

    cout << "\nGetting system time after stopping timer:\n";
    printSystemTime();

    cout << "\nElapsed time (seconds): " << timer.elapsed() << endl;

    return 0;
}