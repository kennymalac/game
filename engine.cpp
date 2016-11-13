#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include "engine.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>


Engine::Engine() {};


//const Container &InitialConfig;
void Engine::destroy() { glfwTerminate(); }

static void glfw_error_callback(int error, const char* description) {
  fprintf(stderr, "Error: %s\n", description);
}

int Engine::initialize() {
  if (!glfwInit()) {
    return -1;}

  GLFWwindow *window;
  GLuint vertex_buffer, vertex_shader, fragment_shader, program;
  GLint mvp_location, vpos_location, vcol_location;
  glfwSetErrorCallback(glfw_error_callback);
    //exit(1);//EXIT_FAILURE);

  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  //transformgmtx4x4
  //

  window = glfwCreateWindow(1024, 768, "Simple example", NULL, NULL);
  if (!window) {
    glfwTerminate();
    //exit(0);//EXIT_FAILURE);
  }
  //glfwSetKeyCallback(window, keyCallback);
  glfwMakeContextCurrent(window);

  GLenum err = glewInit();
  if (GLEW_OK != err) {
    /* Problem: glewInit failed, something is seriously wrong. */
    fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
  }

  // replace GLAD with GLEW
  // gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
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

  Clock eventLoop;

  while (!glfwWindowShouldClose(window)) {
     eventLoop.tick();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  //exit(EXIT_SUCCESS);
  return 0;
}

  void Engine::configure() {
    auto openGL4Enabled = GLEW_VERSION_4_0;

     // Configure opengl version and other internal Engine settings
    if (openGL4Enabled || GLEW_ARB_tessellation_shader) {
      // Bootstrap optional terrain tesselation feature
    }
    else {
      // Employ fractal vertex program shaders
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  }
