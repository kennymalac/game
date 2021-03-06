~TerrainShader::TerrainShader (Grid& g) : (){
  // establish identity objects for shader accessors
  //this->tracePixels = glm::mat4x4
  // RAII - resource access is initialization

  loadFromFile("terrain.vtx.glsl");
  loadFromFile("terrain.frag.glsl");
  BindShaders(this, );
  ready = true;};

TerrainShader::compile() {
  // TODO: solid wireframe geometry shader
  // http://developer.download.nvidia.com/SDK/10/direct3d/Source/SolidWireframe/Doc/SolidWireframe.pdf

  // layout (location=0) in vec4 in_Position
  // layout (location=1) in vec4 in_UVx2;
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);

  //if (showWireframe)
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  //else
  //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  GLint ModelMatrixUniformLocation = 
  GLint ViewMatrixUniformLocation = getUniformLocation ( programId, "ViewMatrix" );
  GLint ProjectionMatrixUniformLocation = getUniformLocation ( programId, "ProjectionMatrix" );

  auto textures{
    Texture{"sampler2D", TextureDim::2D, "ModelMatrix"},
      Texture{"sampler2D", TextureDim::2D}
  };
  
  GLint Texture0UniformLocation = getUniformLocation ( programId, "texture_0" );

  //grassColor
  glActiveTexture(GL_TEXTURE1);

  glUniform1i(quadTexture, 1);
  glUniform1i(quadWidth, );
  glUniform1i(quadHeight);

  glDrawElements ( GL_TRIANGLES, numberOfIndices, GL_UNSIGNED_INT, (GLvoid*)0 );
  // Check for OpenGL error.

  return;
}

// Usage:
// t TerrainShader{grid};
// t.compile

