#include "include/catch.hpp"

#include <entity>

GIVEN("an Entity is being constructed") {

}

GIVEN("a custom Entity is being derived") {
  class TestEntity : Entity{};

  WHEN("the derived Entity class has a set of Components") {
    //
  }

  WHEN("the derived Entity class has no Components") {
    //
  }
}
