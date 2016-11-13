// This code will make using shaders much more usable
// Title: GL polymorphs
// polymorph: (transitive, video games, roguelikes) The transformation of an item or creature into something different by magic. [source: wiktionary]


// ShaderFinderIterator = 


class GLQueryFactory(Query) {
  forwardIterator = ShaderFinderIterator;
  // establish iteration between two loops
  
  }

struct GLFragment {
  // "A Frament is a collection of values produced by the Rasterizer" - OpenGL docs
  virtual GLuint inputFrag = 0;
  virtual Gluint outputFrag = 0;
  //virtual GLuint fragmentShader = 0;
}

  struct GLFragmentShader : GLShader {
    virtual vector<GLFragment *> fragments = 0;
    // serializes GLFragmentShader output into a normalized matrix
    std::ordered_set<glm::mat4x4> normalizeFrags { };
  }

// struct ShaderStack {
//   std::string name;
//   std::stack currentShaders;
//   //logger std::
//   }

struct ShaderProgram {
  boolean ready = false;
  void load ();
  Vbo createVbo ();
  // delete vbo
  // create/delete vao
  }

struct GLShader {
  std::stack<ShaderProgram> compile ();
  std::stack apply ();
  std::string fileName;
  }

