struct FrameDatum {
  // mutable!!!
  std::unordered_map<Texel> renderedTexels;
  //auto timepoint;
}

struct Pos {
  glm::vec3 position;
  glm::vec3 normal;
};

struct TexelFormat {
  //
}

struct Texel {
  Pos pos;
  TexelFormat texcoord;}


struct PosMorphFrame {
  const NUM_VERTS;
  // TODO figure this out
  std::array<NUM_VERTS, Pos> verts;
  PosMorphFrame(NUM_VERTS) : {NUM_VERTS};};


