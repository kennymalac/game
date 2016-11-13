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
  std::chrono::high_resolution_clock counter;
  std::chrono::time_point previous;
  std::chrono::duration<std::chrono::microseconds> sinceLastTick;
  inline time_point now() {
    previous = counter.max();
    sinceLastTick = previous;
    return previous;
  };
  inline void tick() {
    sinceLastTick = now() - previous;
  };}

