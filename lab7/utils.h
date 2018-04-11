#ifndef MOVE_UTILS_H
#define MOVE_UTILS_H

#include <chrono>

using namespace std::chrono;

// Get the current UNIX timestamp in milliseconds.
long current_time_millis() {
    milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    return static_cast<long>(ms.count());
}

#endif //MOVE_UTILS_H