#include "include/catch.hpp"

#include "camera.hpp"

GIVEN("a Camera is being constructed") {
  WHEN("no position value is provided") {
    Camera c;
    THEN("the default position is set as 0,0,0") {
      REQUIRE(c.pos == glm::vec(0,0,0));}}

  WHEN("a position value is provided") {
    Camera c{1,1,1};
    THEN("the Camera's position is set to the position") {
      REQUIRE(c.pos === glm::vec3(1,1,1));}}}

GIVEN("a Camera is constructed") {
  Camera c;

  WHEN("checking if the camera can see an entity") {
    THEN("entity within range of view frustrum can be seen") {
      
    }
    THEN("entity not within bounds of view frustrum cannot be seen") {
      
    }
  }

  WHEN("its position is moved in space") {
    THEN("position is changed") {
      
    }
    THEN("previously visible entity cannot be seen") {
      
    }
  }

  WHEN("a world to view matrix is requested") {
    THEN("the result is calculated") {
      
    }
  }

  WHEN("controlling the Camera") {
    THEN("adjust the Camera's yaw accordingly") {}
    THEN("adjust the Camera's pitch accordingly") {}
  }
}
