#include <experimental/filesystem>
#include <iostream>
#include <fstream>
#include <string>
using namespace std::experimental;


~GLFragmentShader::GLFragmentShader () {
  
  }
~GLVertexShader::GLVertexShader () {
  
}


// Vao ShaderProgram::createVao() {
  
//   //
// }

// std::stack<Vbo> ShaderProgram::createVbo() {
//   // Return vbo stack
//   GLuint vertex_buffer, vertex_shader, fragment_shader;
  
//   }


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

void ShaderProgram::compile() {
  programId = glCreateProgram();
  this->glBootstrap();
}

void ShaderProgram::load() {
  // ShaderPrograms require buffers to be generated first
  

  // Shader Type is part of an enum of GL_VERTEX_SHADER or GL_FRAGMENT_SHADER
  glCreateShaders(SHADER_TYPE);

  glLinkProgram(program);
}


template <typename ... Ts> void BindShaders(ShaderProgram* sp, auto& buffer, const Ts& ... args) {
  int index = 0;
  (sp->bind(&buffer, ++index, args), ...)
}


void ShaderProgram::bind(auto buffer, auto currShader, auto ftype) {
  // Determine the GLShader's type
  // TODO: sometimes we want multiple shader types in the same file?
  // NOTE: emplace only returns a reference in C++17
  if (ftype == ".vtx.glsl") {
    GLVertexShader vtx{};
    auto &shader = loadedShaders::emplace<&buffer>(vtx);
  }
  else if (ftype == ".frag.glsl") {
    GLFragmentShader frag{};
    auto &shader = loadedShaders::emplace<&buffer>(frag);
  }
  else if (ftype == ".tess.glsl") {
    // TODO - tesselation shader
    GLShader shader{};
    auto &shader = loadedShaders::emplace<&buffer>(shader);
  }
  else {
    throw std::domain_error::domain_error(
     "GLShader must have a type.");
  }

  // Now attach the shader to this ShaderProgram
  glAttachShader(programId, &shader->shaderId);}

std::tuple<auto, auto> ShaderProgram::loadFromFile(std::string name) {

  auto location = current_path() / "shaders" / name;
  if (filesystem::exists(location)) {
    auto ftype = location.extension();
    std::ifstream shaderFile(location);
    std::string buffer((std::istreambuf_iterator<char>(shaderFile)),
                       (std::istreambuf_iterator<char>()));


    return {buffer, ftype};}}
