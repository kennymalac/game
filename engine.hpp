#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <chrono>

//#include "space.hpp"

struct Engine {
  void destroy();
  //void glfw_error_callback();
  int initialize();
  void configure();
  //modifySettings();
  //int
  };

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

