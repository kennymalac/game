#include <chrono>
#include <set>
#include <memory>

template <typename precision>
struct Clock {
  // TODO some sort of slicing so multiple updates can happen per one render or vice versa
  using clock = std::chrono::steady_clock;

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

struct Update {
  // Command paradigm is slow
};

template <typename relativeTime, typename precision>
struct Stepper {
  // The precision of the clock is in microseconds
  // The clock tick happens each time findUpdates is called.
  // However the number of steps where updates actually occur is per timeUnit
  // 
  std::shared_ptr<Clock<precision>> clock;
  std::multiset<TimeRecord> records;
  int currStep = 0;
  int slicesPerStep;
  // std::chrono::duration<relativeTime> stepLength;

  // inline auto processUpdates(std::vector<Update&>) {
    
  // }

  inline auto findUpdates() {
    // TODO
  };

  static Stepper create(auto clock, auto slicesPerStep) {
    return Stepper<relativeTime, precision>(clock, slicesPerStep);
  };

  Stepper(auto clock, auto slicesPerStep):
    clock(clock),
    slicesPerStep(slicesPerStep) {}
  // ~Stepper<relativeTime, precision>();

  // Stepper<relativeTime, precision>():
  //   clock(clock),
  //   slicesPerStep(slicesPerStep) {}
  // ~Stepper<relativeTime, precision>();

};

