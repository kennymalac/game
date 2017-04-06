
void TerrainGenerator::initShaders(auto& g) {
  // TODO: use Grid, not untyped array
  // Right now Grid is not used
  TerrainShader t{&g};
  // Assign relevant identifiers
  //t.quad = Quad {texture: }
  //t.quadTexture = glGetUniformLocation(programId, "texture");
  t.quadWidth = glGetUniformLocation(programId, "width");
  t.quadHeight = glGetUniformLocation(programId, "height");
}

TerrainGenerator::createLandscape() {
  using mapType = GL_TEXTURE_2D;
  Grid g;
  // TODO multithreading
  DiamondSquareHeightmap h;
  h::generate(n);
  initShaders(&g);
  // TODO handle half pixels, resolution is int
  quad = GLQuad(glm::vec3(1,1,0),
                glm::vec3(resolution[0] / 2, resolution[1] / 2, 0),
                glm::vec3(resolution[0], resolution[1], 1));
  // Now we have a heightmap.
  glBindTexture(GL_TEXTURE_3D, hm);
  glGetTexImage(GL_TEXTURE_3D, 0, GL_R16F, GL_FLOAT, heightmap_data);

  glViewport(0, 0, resolution[0], resolution[1]);
  // SET PROJECTION
  ortho(0.f,(float)width,(float)height,0.f);
  // SET MODELVIEW
  

  // Setup a mesh to be rendered
  RenderableMesh mesh{};
  mesh.initTextures();

  // // Create a normal map
  // glGenTextures(1, &normalmap);
  // glBindTexture(GL_TEXTURE_3D, normalmap);
  // glTexParameterf(mapType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  // glTexParameterf(mapType, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  // glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP);
  // glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP);
  // glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP);
  // glTexImage3D(GL_TEXTURE_3D, 0, GL_RGB16F, resolution[0], resolution[1],
  //              instances_, 0, GL_LUMINANCE, GL_FLOAT, 0);
  // glBindTexture(GL_TEXTURE_3D, 0);

  // TODO layering the grid is necessary for blendmapping textures
  // 
}

// void displace () {
  
//   }

DiamondSquareHeightmap::~DiamondSquareHeightmap() {
  std::array<double,3> intervals {0.5, 0.8, 0.5};
  std::array<double,3> weights {1.0, 0.8, 1.2};
  std::piecewise_linear_distribution<double>
    distribution (intervals.begin(), intervals.end(), weights.begin());

  // TODO make use of distribution
}

void DiamondSquareHeightmap::generate(n) {
  // begin with 2D square array of width and height 2^n + 1
  // generates a plasma fractal using the diamond-square algorithm
  // TODO: implement Lewis algorithm for more realistic landscapes
  // TODO: make use of Grid
  // WARNING: this is all CPU bound

  int wh = sqrt(2, n) + 1;
  std::array<wh, array<wh, double>> heightmap = {0.0};

  auto averageOffset = 128.0;

  //squares

  for (int sideLength = wh-1; sideLength >= 2; sideLength /= 2, averageOffset /= 2.0) {
    var halfSegment = sideLength / 2;

    for (auto x = 0; x < wh - 1; x += sideLength) {
      for (auto y = 0; y < wh - 1; y += sideLength) {
        // corners of the current square
        // upper left corner - heightmap[x, y]
        // upper right corner - heightmap[x + sideLength][y]
        // lower left corner - heightmap[x][y + sideLength]
        // lower right corner - heightmap[x + sideLength][y + sideLength]
        // calculate the average of existing corners
        auto mean = heightmap[x][y] +
          heightmap[x + sideLength][y] +
          heightmap[x][y + sideLength] +
          heightmap[x + sideLength][y + sideLength];

        mean /= 4.0;

        // the center of the square
        heightmap[x + halfSegment][y + halfSegment] = mean +
          (this->randomVal(x, y) * 2 * averageOffset) - averageOffset;

        // 
      }
    }

    // TODO: calculate triangulation of diamonds in vertex shader
    // generate the diamond values
    for (var x = 0; x < wh - 1; x += halfSegment) {
      for (var y = (x + halfSegment) % sideLength; y < wh - 1; y += sideLength) {
        auto mean = heightmap[(x - halfSegment + wh-1) % (wh-1)][y] +
          heightmap[(x + halfSegment) & (wh-1)][y] +
          heightmap[x][(y + halfSegment) % (wh-1)] +
          heightmap[x][(y - halfSegment + wh-1) % (wh-1)];

        mean /= 4.0;

        // new value is the average plus a random offset
        mean += ( * 2 * averageOffset) - averageOffset;
        // set the center of the diamond to the average
        heightmap[x][y] = mean;

        // wrap values on the edges of the diamonds
        if (x == 0) data[wh-1][y] = mean;
        if (y == 0) data[x][wh-1] = mean;
      }
    }
  }

  // TODO: create sugar using spherical coordinates
  // feed sugar values into simple color fragment shader if configured to display sugar

  // TODO: just loop over the glm::mat2, no need for C style array
  memcpy(glm::value_ptr(hm), heightmap, sizeof(heightmap));}
