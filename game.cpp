#pragma once
#include <space.hpp>

void Game::init() {
  Camera camera;
  const int mvpLocation = 1;
}

void Game::loop() {
  mvp_location = 1;
  float ratio;
  int width, height;
  glfwGetFramebufferSize(window, &width, &height);
  ratio = width / (float)height;
  glViewport(0, 0, width, height);
  glClear(GL_COLOR_BUFFER_BIT);
  //glFlush();

  GLuint VBO;
  glGenBuffers(1, &VBO);


  auto view = camera.getWorldToViewMatrix();


  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::value_ptr(view)), glm::value_ptr(view), GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
  glEnableVertexAttribArray(0);

  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glfwSwapBuffers(window);
  glfwPollEvents();
  float ratio;
  int width, height;
  glfwGetFramebufferSize(window, &width, &height);
  ratio = width / (float)height;
  glViewport(0, 0, width, height);
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();

  //glUniformMatrix4fv(2);
  //glm::matrix_transform::ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);


  //glUniformMatrix4fv(mvp_location, 1, GL_FALSE, glm::value_ptr(mvp));
  //glDrawArrays(GL_TRIANGLES, 0, 3);
  glfwSwapBuffers(window);
  glfwPollEvents();}
