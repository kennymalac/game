#include "include/catch.hpp"

#include <mesh>

GIVEN("a RenderableMesh is being contructed") {
  RenderableMesh mesh{};

  THEN("the values must be allocated memory") {
    
  }

}

// DESCRIPTION: Description of a RenderableMesh
// 

GIVEN("a RenderableMesh is constructed") {
  RenderableMesh mesh{};

  WHEN("setting up a coordinates buffer") {
    THEN("the vertex attribute array is enabled") {
      REQUIRE_CALL(, glEnableVertexAttribArray)
    }
    THEN("the vertex attribute count is returned") {
      REQUIRE("")
    }
  }

  WHEN("the mesh is being drawn") {
    THEN("mesh coordinate buffer reference is provided") {
      //
    }
  }

  // WHEN("")
}
