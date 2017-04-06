RenderableMesh(vector<Vertex>& vertices, vector<GLuint>& indices, vector<Texture>& textures) {
  this->vertices = vertices;
  this->indices = indices;
  this->textures = textures;

  this->setupBuffers();
}

auto RenderableMesh::setupBuffers() {
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  //TODO fill vertex indices

  /* DESCRIPTION */
  /* The relationship between the entity and the surrounding visual hierarchy remains encapsulated in the Renderable Mesh
   * TASK: Construct a web of interleaved components that pertain themselves to the coordinate matrices
   * The Entities themselves as visual objects are indexed in their corresponding Element Buffers
   * 
   * 
   */

  // Generate a buffer for the VBO indices
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glBufferData(GL_ARRAY_BUFFER, VBO);
  glBufferData(vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,
               indices.size() * sizeof(GLuint),
               &indices[0], GL_STATIC_DRAW);

  // coordinate systems in the heap
  //   int positionsBufferID, normalsBufferID, texturesCoordBufferID;
 std:array<int, 3> coordBuffers = [
  createCoordBuffer(3, 0),
  createCoordBuffer(3, offsetof(Vertex, normal)),
  createCoordBuffer(2, offsetof(Vertex, textureCoords))];

  glBindVertexArray(0);
  return coordBuffers;};

auto RenderableMesh::bind() {
  glBindVertexArray(this->VBO);
};

auto RenderableMesh::Textures(auto& shader) {
  for (auto texture : this->textures) {
    texture.init(shader->programId);}

  bindTextures(this->textures);
};

auto RenderableMesh::draw() {
  // Bind the VAO and then draw the EBO
  glBindVertexArray(this->VAO);
  glDrawElements(
    GL_TRIANGLES,
    this->indices.size(),
    GL_UNSIGNED_INT,
    (void*)0);
  glBindVertexArray(0);
};
