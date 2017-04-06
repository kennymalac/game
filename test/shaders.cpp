#include "include/catch.hpp"

// TEST_CASE("group of related tests") {
//   // Executed for each and every section
//   REQUIRE(1 == 1);

//   SECTION("series of requirements to be followed") {
//     // REQUIRE(cond == true);
//   }
// }

GIVEN("a ShaderProgram is initialized") {
  WHEN("a shader file is being loaded") {
    THEN("throw an error if the file is unavailable") {
      CHECK_THROWS_AS(shaderProgram.loadFromFile("undefined.test.glsl"), filenotavailableexception);}

    THEN("the buffer and a filetype is returned") {
      //REQUIRE()
      }}

  WHEN("a shader type is being deduced") {
    THEN("throw a domain error if the filetype is invalid") {
        CHECK_THROWS_AS(shaderProgram.bind(buffer, idx, "invalidtype.glsl"), std::domain_error::domain_error)}
    THEN("deduce valid types properly in all cases") {
      REQUIRE(msg);
      // require that the instance created by the shader bind process is the correct type
      // REQUIRE(typeof(vtxShader) == typeof(GLVertexShader));
      // REQUIRE(typeof(fragShader) == typeof(GLFragmentShader));
      // REQUIRE(typeof(tessShader) == typeof(GLTesselationShader));
      // REQUIRE();
    }}

  WHEN("a shader is being binded") {
      shaderProgram.bind(buffer, 0, "")
    TEHN("a shader is appended to the queue of shaders to be processed") {
      REQUIRE(queue.length() == 0)
      // REQUIRE(queue.length() == 1)
      }}

  WHEN() {
    
  }
}

//GIVEN("a vertex shader") {}
//GIVEN("a fragment shader") {}
//GIVEN("a tesselation shader") {}
