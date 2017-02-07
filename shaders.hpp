#pragma once

// This code will make using shaders much more usable
// Title: GL polymorphs
// polymorph: (transitive, video games, roguelikes) The transformation of an item or creature into something different by magic. [source: wiktionary]


// ShaderFinderIterator = 


// class GLQueryFactory(Query) {
//   forwardIterator = ShaderFinderIterator;
//   // establish iteration between two loops
  
//   }

struct GLFragment {
  // "A Fragment is a collection of values produced by the Rasterizer" - OpenGL docs
  virtual GLuint inputFrag = 0;
  virtual Gluint outputFrag = 0;
  //virtual GLuint fragmentShader = 0;
  };

enum AbstractGLCall {
  // function type
  // Work on this later
};

struct GLFragmentShader : GLShader {
  virtual vector<GLFragment *> fragments = 0;
  // serializes GLFragmentShader output into a normalized matrix
  std::ordered_set<glm::mat4x4> normalizeFrags { };
  GLFragmentShader(&buffer) : GLShader(&buffer);
  };

struct GLVertexShader : GLShader {
  // something
  };

// struct ShaderStack {
//   std::string name;
//   std::stack currentShaders;
//   //logger std::
//   }

class ShaderProgram {
public:
  void load ();
  GLShader loadFromFile ();
  //Vbo createVbo ();
  // delete vbo
  // create/delete vao
private:
  //const std::map<std::string, GLuint> shaders;
  std::queue<std::unique_ptr<GLShader>> loadedShaders;
  GLuint programId;
  boolean ready = false;
  };

struct GLShader {
  GLuint shaderId;
  std::string buffer;
  void compile ();
  GLShader(std::string buffer) : buffer (buffer);};


