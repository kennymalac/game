#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/constants.hpp> // glm::pi

// The Camera is controlled by it's mvp. The model view projection matrix determines its display method
glm::mat4 MVP(float translate, glm::vec2 const& rotate)
{
  float z = 0.5 / glm::tan(glm::radians(fieldOfView_y / 2.f));
  glm::mat4 projection = glm::perspective(fieldOfView_y, 1.f, 0.5f, 100.f);
  glm::mat4 view = glm::lookAt(this->position, this->origin,);

  //glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -translate);)
  
  view = glm::rotate(view, rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
  glm::mat4 model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
  return projection * view * model;
}

Camera::Camera Camera() {
  // TODO - all these constants need to be easily tweakable at object creation time
  auto position = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
  
}

Camera::Camera : radius(10.0f);
Camera::Camera : viewDirection(0.0f, 0.0f, -1.0f);


//glm::rotate??
void Camera::adjustPitch(float pitchFactor) {
  position[0] += sin(pitchFactor) * radius;};

void Camera::adjustYaw(float yawFactor) {
  position[1] += cos(yawFactor) * radius;};

void Camera::adjustRoll(float rollFactor) {
  position[2] += sin(rollFactor) * radius;};

vector<float> Camera::calcPitchInterpolation(float pitchFactor, int interpolation) {
  // std::piecewise_linear_distribution<double>
  //   distribution (intervals.begin(), intervals.end(), weights.begin());
};
vector<float> Camera::calcYawInterpolation(float yawFactor, int interpolation) {
  // return ;
  view = glm::rotate(view, yawFactor, glm::vec3(-1.0f, 0.0f, 0.0f));
};
vector<float> Camera::calcRollInterpolation(float rollFactor, int interpolation) {
  // return ;
  view = glm::rotate(view, yawFactor, glm::vec3(0.0f, 0.0f, -1.0f));

};


// This getter retrieves the model view projection matrix
glm::mat4 Camera::getWorldToViewMatrix() const {
  return glm::lookAt(this->position, this->position + viewDirection);
}





