#pragma once
#include <glm/gtc/type_ptr.hpp>

class Heightmap  {
public:
  //void applyDiffusion();
  int longitudeRange;
  int latitudeRange;
  array<2, int> resolution;

  void generateHeightmap;
private:
  glm::mat2 hm;};
