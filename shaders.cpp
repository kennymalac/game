Vao ShaderProgram::createVao() {
  
  //
}

std::stack<Vbo> ShaderProgram::createVbo() {
  // Return vbo stack
  GLuint vertex_buffer, vertex_shader, fragment_shader;
  
  }

ShaderProgram::loadInShaderCache() {
  // We should be able to add shaders to the shader cache at runtime.
  this->shaders
  }

void ShaderProgram:glCheckErrors() {
  for(GLenum err; (err = glGetError()) != GL_NO_ERROR;) {
    // Check for OpenGL error.
    fprintf('opengl error: %s', std::static_cast<std::string> err);
  }
}

void ShaderProgram::glBootstrap() {
   GLuint vboID;
   glGenVertexArrays( 1, &vboID );
   glCheckErrors();

   glBindVertexArray( vboID );
   glCheckErrors();

   // [SimpleTextureShader.vertex.glsl] 
   // layout (location=0) in vec4 in_Position
   // layout (location=1) in vec4 in_UVx2;
   glEnableVertexAttribArray ( 0 ); 
   glEnableVertexAttribArray ( 1 );
   // Check for OpenGL error.

   GLuint vertexBufferID;
   GLuint indexBufferID;
   glGenBuffers ( 1, &vertexBufferID );
   glGenBuffers ( 1, &indexBufferID );
   // Check for OpenGL error.

   glBindBuffer ( GL_ARRAY_BUFFER, vertexBufferID );
   // Check for OpenGL error.

   // In this case [sizeof ( YOURVERTEXDATA )] = 32)
   unsigned int vertSize = sizeof ( YOURVERTXDATA );
   unsigned int size = numVerticesInModel * vertSize ;
   glBufferData ( GL_ARRAY_BUFFER, size, VERTEXDATA, GL_STATIC_DRAW );
   // Check for OpenGL error.

   glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, vertSize, 0 );
   glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, vertSize, 16 );
   // Check for OpenGL error.

   glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER, indexBufferID );
   // Check for OpenGL error.

   glBufferData ( GL_ELEMENT_ARRAY_BUFFER, TOTALSIZEINBYTES, pIndexArrayLocal, GL_STATIC_DRAW);
   // Check for OpenGL error.

   glBindVertexArray( 0 );
   // Check for OpenGL error.
}

void ShaderProgram::load() {
  // ShaderPrograms require buffers to be generated first
  

  // Shader Type is part of an enum of GL_VERTEX_SHADER or GL_FRAGMENT_SHADER
  glCreateShaders(SHADER_TYPE);
  shaders = assembleShaders();
  for (auto &s : shaders) {
    glAttachShader(program, &s);
  }

  glLinkProgram(program);
}


// maybe use include filesystem because reasons
ShaderProgram::loadFromDisk(std::string location) {
  ofstream of(location);
  streambuf* origBuf = cout.rdbuf();
  cout.rdbuf(of.rdbuf());
}

// 
