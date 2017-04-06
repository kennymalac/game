// struct TexelFormat {
//   //

// };

struct Texel {
  //glm::vec3 ;
  std::vec2 texcoords;};


struct Texture {
  GLuint id;
  // TODO put texture type in enum/variant
  std::string type;
  TextureDimension dimension;
  Glint uniformLocation;
  std::string name;

  //static TextureCount;

  inline void init(GLint programId) {
    uniformLocation = glGetUniformLocation(programId, name);
  };

  Texture(dimension, typeId, name) : {dimension; typeId; name;}};


enum TextureDimension {
  2D = GL_TEXTURE_2D,
  3D = GL_TEXTURE_3D
};

enum GL_TextureN {
  1 = GL_TEXTURE1,
  2 = GL_TEXTURE2,
  3 = GL_TEXTURE3,
  4 = GL_TEXTURE4,
  5 = GL_TEXTURE5,
  6 = GL_TEXTURE6,
  7 = GL_TEXTURE7,
  8 = GL_TEXTURE8,
  9 = GL_TEXTURE9,
  10 = GL_TEXTURE10,
  11 = GL_TEXTURE11,
  12 = GL_TEXTURE12,
  13 = GL_TEXTURE13,
  14 = GL_TEXTURE14,
  15 = GL_TEXTURE15
};
