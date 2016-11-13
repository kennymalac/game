#pragma once

// Datatype for managing transitions. Provides iterators to transition into different Scene states
struct TransitionMap {
  
}

  struct Transition {
    virtual nextScene() {
      // fire the next scene's initializer and run the next scene
    }
    virtual prevScene() {
      // go to the previous scene
    }
  }
