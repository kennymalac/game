#pragma once
#include <glm/gtc/type_ptr.hpp>

struct Texture;
const grassColor = Texture{color: 0.0f, 1.0f, 0.0f, 1.0f};
// const waterColor = Texture{color: 0.0f, 0.0f, 1.0f, 1.0f};
// const dirtTexture = Texture{color: 0.0f, 0.0f, 1.0f, 1.0f};
// const sandTexture = Texture{color: 0.0f, 0.0f, 1.0f, 1.0f};

class TerrainGenerator  {
  void initShaders(auto& grid);
  void createLandscape();}

class DiamondSquareHeightmap : Heightmap {
  void generate(n);}

class Heightmap {
public:
  //void applyDiffusion();
  int longitudeRange;
  int latitudeRange;
  array<2, int> resolution;
  std::default_random_engine seeder;

  
  void generate = 0;
private:
  glm::mat2 hm;};


