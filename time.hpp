#include <chrono>

struct Clock {
  // TODO some sort of slicing so multiple updates can happen per one render or vice versa
  using clock = std::chrono::steady_clock;
  using precision = std::chrono::microseconds;

  std::chrono::time_point<clock, precision> T, previousT;
  precision sinceLastTick;

  inline std::chrono::time_point<clock, precision> now() {
    previousT = T;
    return std::chrono::time_point_cast<precision>(clock::now());
  };
  inline void tick() {
    T = now();
    sinceLastTick = std::chrono::duration_cast<precision>(T - previousT);
  };};

struct TimeSlice {
  //
};

struct TimeRecord {
  //t
};

struct SunDial {
  // sugar time
};

struct Stepper {
  Clock clock;
  std::multiset<TimeRecord> records;
  int currStep = 0;
  int slicesPerStep;
  std::chrono::duration<precision> stepLength;

  Stepper(auto stepLength, slicesPerStep): stepLength (stepLength)};
