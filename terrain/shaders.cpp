~TerrainShader::TerrainShader (Grid& g) : (){
  // establish identity objects for shader accessors
  //this->tracePixels = glm::mat4x4
  // RAII - resource access is initialization
  loadFromFile("terrain.vtx.glsl");
  loadFromFile("terrain.frag.glsl");
  ready = true;};

// Usage:
// t TerrainShader{grid};
// t.compile

