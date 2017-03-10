#pragma once

class Camera {
  glm::vec3 position;
  glm::vec3 viewDirection;
  const glm::vec3 UP = glm::vec3(0,0,1);
public:
  Camera(auto pos) : position glm::vec3{0,0,0};
  glm::mat4 getWorldToViewMatrix const;
  bool canSee(Entity& e);
}
