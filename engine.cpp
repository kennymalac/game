#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <memory>

#include "engine.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>


//const Container &InitialConfig;
void Engine::destroy() { glfwTerminate(); }


// TODO: error logger
static void glCheckErrors() {
  for(GLenum err; (err = glGetError()) != GL_NO_ERROR;) {
    // Check for OpenGL error.
    fprintf(stdout, "opengl error: %s\n", glewGetErrorString(err));
  }}

static void glfw_error_callback(int error, const char* description) {
  fprintf(stderr, "Error: %s\n", description);}

int Engine::initialize() {
  if (!glfwInit()) {
    return -1;}

  GLFWwindow *window;
  GLuint vertex_buffer, vertex_shader, fragment_shader, program;
  GLint mvp_location, vpos_location, vcol_location;
  glfwSetErrorCallback(glfw_error_callback);
    //exit(1);//EXIT_FAILURE);

  // Decide profile
  // try { ... } catch () { .... } 
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  // TODO better settings
  int width = 1024;
  int height = 768;

  window = glfwCreateWindow(width, height, "Simple example", NULL, NULL);
  if (!window) {
    glfwTerminate();}
  //glfwSetKeyCallback(window, keyCallback);
  glfwMakeContextCurrent(window);

  GLenum err = glewInit();
  if (GLEW_OK != err) {
    /* Problem: glewInit failed, something is seriously wrong. */
    fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
  }

  // glfwSwapInterval(1);
  // // NOTE: OpenGL error checks have been omitted for brevity
  // glGenBuffers(1, &vertex_buffer);
  // glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
  // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  // vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  // glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
  // glCompileShader(vertex_shader);
  // fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
  // glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
  // glCompileShader(fragment_shader);
  // program = glCreateProgram();
  // glAttachShader(program, vertex_shader);
  // glAttachShader(program, fragment_shader);
  // glLinkProgram(program);
  //mvp_location = glGetUniformLocation(program, "MVP");
  //vpos_location = glGetAttribLocation(program, "vPos");
  //vcol_location = glGetAttribLocation(program, "vCol");
  // glEnableVertexAttribArray(vpos_location);
  // glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
  //                       sizeof(float) * 5, (void *)0);
  // glEnableVertexAttribArray(vcol_location);
  // glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
  //                       sizeof(float) * 5, (void *)(sizeof(float) * 2));

  glViewport(0, 0, width, height);

  // Event timezone
  int ets = 24;
  // Observer timezone
  int ots = 144;
  // Render timezone
  // TODO fps configurable at run-time
  int fps = 60;

  // Sync our event, observer, and render steppers unto the same clock
  using precision = std::chrono::microseconds;
  auto clock = std::make_shared<Clock<precision>>();
  clock->previousT = clock->now();

  // Now create a stepper for each loop that runs updates a certain number of times per second
  using SecStepper = Stepper<std::chrono::seconds, precision>;
  // SecStepper eventLoop{clock, ets};
  // SecStepper observerLoop{clock, ots};
  // SecStepper renderLoop{clock, fps};
  auto eventLoop = SecStepper::create(clock, ets);
  auto renderLoop = SecStepper::create(clock, fps);

  // TODO - single threaded dispatch is slow, improve this
  while (!glfwWindowShouldClose(window)) {
    // for (auto ets: eventLoop.step()) {
    //   for (auto &triggers: ets->findUpdates()) {
        
    //   }};
    // for (auto ots: observerLoop.step()) {
    //   for (auto &updates: ots->findUpdates()) {
    //     &u->process();
    //   }}
    // for (auto fpss: renderLoop.step()) {
    //   for (auto &renderable: fpss->findUpdates()) {
    //     &r.draw();}

    clock->tick();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  //exit(EXIT_SUCCESS);
  return 0;
}
  // void Engine::configure() {
  //   auto openGL4Enabled = GLEW_VERSION_4_0;

  //    // Configure opengl version and other internal Engine settings
  //   if (openGL4Enabled || GLEW_ARB_tessellation_shader) {
  //     // Bootstrap optional terrain tesselation feature
  //   }
  //   else {
  //     // Employ fractal vertex program shaders
  //   }

  //   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  //   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  // }
