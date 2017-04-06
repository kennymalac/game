struct FrameDatum {
  // mutable!!!
  std::unordered_map<Texel> renderedTexels;
  //auto timepoint;
};

struct Vertex {
  glm::vec3 position;
  glm::vec3 normal;
  glm::vec2 texcoords;
};

struct PosMorphFrame {
  const numVerticesInModel;
  // TODO figure this out
  std::array<numVertices, Vertex> verts;
  PosMorphFrame(numVertices) : {numVertices};};


