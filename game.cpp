#pragma once
#include <space.hpp>

class Game {
public:
  void loop():
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

    auto mvp = camera(1.f);

    GLfloat radius = 10.0f;
    GLfloat camX = sin(glfwGetTime()) * radius;
    GLfloat camZ = cos(glfwGetTime()) * radius;
    glm::mat4 view;

    view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));


    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::value_ptr(view)), glm::value_ptr(view), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(1.0, 0.0, 0.0);
    int xsize=100,ysize=100;
    for(int j=0;j<10;j++)
      {

        xsize=0;
        for(int i=0;i<10;i++)
          {
            glBegin(GL_POLYGON);
            glVertex3f(-50.0+xsize, -50.0+ysize, 0.0);
            glVertex3f(-40.0+xsize, -50.0+ysize, 0.0);
            glVertex3f(-40.0+xsize, -40.0+ysize, 0.0);
            glVertex3f(-50.0+xsize, -40.0+ysize, 0.0);
            glEnd();
            xsize+=10.0;
          }
        ysize+=10.0;
      }
    glDrawElements(GL_POLYGON, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    //glm::vec2 v23;
    //glUniformMatrix4fv(2);
    //glm::rotate(m, m, (float)glfwGetTime());
    //glm::matrix_transform::ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    // glUseProgram(program);
    //glUniformMatrix4fv(mvp_location, 1, GL_FALSE, glm::value_ptr(mvp));
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }    mvp_location = 1;
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float)height;
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    //glFlush();

    GLuint VBO;
    glGenBuffers(1, &VBO);

    auto mvp = camera(1.f);

    GLfloat radius = 10.0f;
    GLfloat camX = sin(glfwGetTime()) * radius;
    GLfloat camZ = cos(glfwGetTime()) * radius;
    glm::mat4 view;

    view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));


    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::value_ptr(view)), glm::value_ptr(view), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(1.0, 0.0, 0.0);
    int xsize=100,ysize=100;
    for(int j=0;j<10;j++)
      {

        xsize=0;
        for(int i=0;i<10;i++)
          {
            glBegin(GL_POLYGON);
            glVertex3f(-50.0+xsize, -50.0+ysize, 0.0);
            glVertex3f(-40.0+xsize, -50.0+ysize, 0.0);
            glVertex3f(-40.0+xsize, -40.0+ysize, 0.0);
            glVertex3f(-50.0+xsize, -40.0+ysize, 0.0);
            glEnd();
            xsize+=10.0;
          }
        ysize+=10.0;
      }
    glDrawElements(GL_POLYGON, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    //glm::vec2 v23;
    //glUniformMatrix4fv(2);
    //glm::rotate(m, m, (float)glfwGetTime());
    //glm::matrix_transform::ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    // glUseProgram(program);
    //glUniformMatrix4fv(mvp_location, 1, GL_FALSE, glm::value_ptr(mvp));
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

protected:
Scene defaultScene;

private:
void update(float ms) {
for (auto &x : entities)
  x->update(ms);
}
void draw() {
for (auto &x : renderables)
  x->draw();
}
}
