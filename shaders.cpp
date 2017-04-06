#include <experimental/filesystem>
#include <iostream>
#include <fstream>
#include <string>
using namespace std::experimental;


~GLFragmentShader::GLFragmentShader (auto buffer) {
  shaderId = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(shaderId, 1, &buffer, NULL);};

GLFragmentShader::tryCompile() {
  // inputFrags, outputFrags
  glCompileShader(shaderId);
  //
};


~GLVertexShader::GLVertexShader (auto buffer) {
  shaderId = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(shaderId, 1, &buffer, NULL);};

GLVertexShader::tryCompile() {
  glCompileShader(shaderId);};


// std::stack<Vbo> ShaderProgram::createVbo() {
//   // Return vbo stack
//   GLuint vertex_buffer, vertex_shader, fragment_shader;
//   }

void ShaderProgram::glBootstrap(RenderableMesh& mesh) {
  //vertex_buffer, vertex_shader, fragment_shader,
  GLuint mvp_location, vpos_location, vcol_location;

  GLuint vboID;
  glCheckErrors();

  //mesh.bind();

  glCheckErrors();

  // Check for OpenGL error.

  // 
  GLuint vertexBufferID;

  // The Element Buffer Object's id
  GLuint indexBufferID;
  glGenBuffers (1, &vertexBufferID);
  glGenBuffers (1, &indexBufferID);
  // Check for OpenGL error.

  glBindBuffer (GL_ARRAY_BUFFER, vertexBufferID);
  // Check for OpenGL error.

  unsigned int vertSize = sizeof (Vertex);
  GLuint* vertexData;
  unsigned int size = numVerticesInModel * vertSize;
  GLuint* pIndexArrayLocal = new GLuint[size];
  glBufferData ( GL_ARRAY_BUFFER, size, vertexData, GL_STATIC_DRAW );
  // Check for OpenGL error.

  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, vertSize, 0 );
  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, vertSize, 16 );
  // Check for OpenGL error.

  glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER, indexBufferID );
  // Check for OpenGL error.

  glBufferData ( GL_ELEMENT_ARRAY_BUFFER, vertSize, pIndexArrayLocal, GL_STATIC_DRAW);
  // Check for OpenGL error.

  glBindVertexArray( 0 );
  // Check for OpenGL error.
};

/* ShaderProgram - compile
 * Tries to compile a set of shaders and errors on invalid compilation
 */
void ShaderProgram::compile() {
  programId = glCreateProgram();
  this->glBootstrap();

  for (auto &shader : loadedShaders) {
    shader->tryCompile();

    // Check compilation status
    GLint isCompiled = 0;
    glGetShaderiv(shader.id, GL_COMPILE_STATUS, &isCompiled);

    if (isCompiled == GL_FALSE) {
      // Acquire the error log if something went wrong.
      unsigned int logLength = 0;
      glGetShaderiv(shader.id, GL_INFO_LOG_LENGTH, &logLength);

      char errorLog[logLength];
      glGetShaderInfoLog(shader.id, logLength, NULL, errorLog);

      // Discard
      glDeleteShader(vertexShader);

      // cerr until engine debug console is refined
      cerr << "Shader compile error: " << endl;
      cerr << error << endl;
      throw runtime_error("Shader couldn't compile");

    }}};

/* ShaderProgram - load
 * Links a ShaderProgram after compiling the Shader sources
 * All setup for the shader
 */
void ShaderProgram::load() {
  // ShaderPrograms require buffers to be generated first
  //this->compile();
  // Shader Type is part of an enum of GL_VERTEX_SHADER or GL_FRAGMENT_SHADER

  glLinkProgram(program);
  // Bind has to happen after shaders are compiled
};


template <typename ... Ts> void BindShaders(ShaderProgram* sp, auto& buffer, const Ts& ... args) {
  int index = 0;
  (sp->bind(&buffer, ++index, args), ...)};


/* ShaderProgram - bind
 * Determines the shader type and emplaces a buffer unto an initialized Shader object conforming to that type
 */
void ShaderProgram::bind(auto buffer, auto currShader, auto ftype) {
  // Determine the GLShader's type
  // TODO: sometimes we want multiple shader types in the same file?
  // NOTE: emplace only returns a reference in C++17
  if (ftype == ".vtx.glsl") {
    GLVertexShader vtx{};
    auto &shader = loadedShaders::emplace<&buffer>(vtx);
  else if (ftype == ".frag.glsl") {
    GLFragmentShader frag{};
    auto &shader = loadedShaders::emplace<&buffer>(frag);}
  else if (ftype == ".tess.glsl") {
    // TODO - tesselation shader
    GLShader shader{};
    auto &shader = loadedShaders::emplace<&buffer>(shader);}
  else {
    throw std::domain_error::domain_error(
     "GLShader must have a type.");}

  // Now attach the shader to this ShaderProgram
  glAttachShader(programId, &shader->shaderId);}};



/* ShaderProgram - loadFromFile
 * Currently hardcoded to load a shader file conforming to file.<shadertype>.glsl in the shaders/ directory
 */
std::tuple<auto, auto> ShaderProgram::loadFromFile(std::string name) {
  // TODO save name of file and also don't hardcode shaders directory
  auto location = current_path() / "shaders" / name;
  if (filesystem::exists(location)) {
    auto ftype = location.extension();
    std::ifstream shaderFile(location);
    std::string buffer((std::istreambuf_iterator<char>(shaderFile)),
                       (std::istreambuf_iterator<char>()));


    return {buffer, ftype};}};
