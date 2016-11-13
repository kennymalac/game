#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/constants.hpp> // glm::pi

// The Camera is controlled by it's mvp. The model view projection matrix determines its display method

// This getter retrieves the model view projection matrix
Camera::Camera Camera() {
  // TODO - all these constants need to be easily tweazable at object creation time
  glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f)
}

glm::mat4 getMVP(float translate, glm::vec2 const& rotate))
{
  //glm::mat4 projection = ;
  

  glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
  View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
  View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
  glm::mat4 model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
  return projection * view * model;
}

Camera::Camera : viewDirection(0.0f, 0.0f, -1.0f)
glm::mat4 Camera::viewWorldToViewMatrix() const {
  return glm::lookAt(this->position, this->position + viewDirection);
}





