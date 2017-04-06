#pragma once

class Camera {
  glm::vec3 position;
  glm::vec3 viewDirection;
  unsigned float fieldOfView_y = 45.f;

  glm::vec3 origin;

  const glm::vec3 UP = glm::vec3(0,0,1);
public:
  Camera(auto pos, auto origin)
    : position glm::vec3<int>{0.f,0.f,0.f},
    : origin glm::vec3<int>{0.5, 0.5};

  glm::mat4 getWorldToViewMatrix const;
  bool canSee(Entity& e);
  void adjustPitch(float pitchFactor);
  void adjustYaw(float yawFactor);
  vector<float> calcPitchInterpolation(float pitchFactor, unsigned int interpolation);
  vector<float> calcYawInterpolation(float yawFactor, unsigned int interpolation);
  vector<float> calcRollInterpolation(float rollFactor, unsigned int interpolation);
};
