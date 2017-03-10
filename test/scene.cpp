#include "include/catch.hpp"

#include <scene>

GIVEN("a Scene is being constructed") {
  WHEN("") {
    
  }
}

GIVEN("a Scene") {
  WHEN("is in arrangement") {
    Scene scene1,scene2,scene3;
    std::map<ComponentID, Scene> scenes {scene1, scene2, scene3};

    THEN("a Stepper transitions it into Being") {
      
    }
  }
}


GIVEN("a SceneManager owns Scenes") {
  SceneManager sceneManager;

  WHEN("a transition is being conducted") {
    THEN("") {
      
    }
    THEN("order of application must be preserved") {
      
    }
  }

  WHEN("the current Scene is requested") {
    THEN("the correct Scene reference is returned") {
      
    }
  }

  WHEN("the SceneManager's backdrop is reset") {
    THEN("clear all unnecessary transition state") {
      
    }
  }
}
