#include "include/catch.hpp"

#include <glm/vec3.hpp> // glm::vec3

#include "camera.hpp"
#include "entity.hpp"

GIVEN("a Camera is being constructed") {
  WHEN("no position value is provided") {
    Camera c;
    THEN("the default position is set as 0,0,0") {
      REQUIRE(c.pos == glm::vec3(0,0,0));}}

  WHEN("a position value is provided") {
    Camera c{1,1,1};
    THEN("the Camera's position is set to the position") {
      REQUIRE(c.pos == glm::vec3(1,1,1));}}}

GIVEN("a Camera is constructed") {
  Camera cam;

  WHEN("checking if the camera can see an entity") {
    THEN("entity within range of view frustrum can be seen") {
      Entity e1{0,0,0};
      REQUIRE(cam.canSee(e1) == true);
    }
    THEN("entity not within bounds of view frustrum cannot be seen") {
      // TODO test using range extensions
      Entity e2{5000,0,0};
      REQUIRE(cam.canSee(e2) == false);
    }
  }

  WHEN("its position is moved in space") {
    cam.position = glm::vec3{2000,0,0};
    THEN("position is changed") {
      // Woah!!! mutability
      REQUIRE(cam.position == glm::vec3{2000,0,0});}
    THEN("previously visible entity cannot be seen") {
      Entity e2{0,0,0};
      REQUIRE(cam.canSee(e2) == true);}
  }

  WHEN("a world to view matrix is requested") {
    THEN("the result is calculated") {
      REQUIRE_CALL(cam.getWorldToViewMatrix(), glm::lookAt);
    }
  }

  // Adjusting the Camera executes immediately
  WHEN("adjusting the Camera") {
    THEN("change the Camera's yaw according to the yaw factor") {
      cam.adjustYaw(1.0f);
      //REQUIRE();
    }
    THEN("change the Camera's pitch according to the pitch factor") {
      cam.adjustPitch(1.0f);
      //REQUIRE();
    }
    THEN("change the Camera's roll according to the roll factor") {
      cam.adjustRoll(1.0f);
      //REQUIRE();
    }
  }

  // If a Camera is being auto-controlled,
  // the command is to change the camera over time.
  WHEN("auto-controlling the Camera") {
    THEN("interpolate the Camera's yaw accordingly") {
      // vector<float> yawAdjustValues = cam.calcPitchInterpolation(1.0f, 5);

      //REQUIRE();
    }
    THEN("interpolate the Camera's pitch accordingly") {
      // vector<float> pitchAdjustValues = cam.calcYawInterpolation(1.0f, 5);

      //REQUIRE();
    }
  }
}
