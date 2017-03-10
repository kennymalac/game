auto RenderableMesh::setupBuffers() {
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glBufferData(GL_ARRAY_BUFFER, VBO);
  glBufferData(vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,
               indices.size() * sizeof(GLuint),
               &indices[0], GL_STATIC_DRAW);

  //   int positionsBufferID, normalsBufferID, texturesCoordBufferID;
 std:array<int, 3> coordBuffers = [
  createCoordBuffer(3, 0),
  createCoordBuffer(3, offsetof(Vertex, normal)),
  createCoordBuffer(2, offsetof(Vertex, textureCoords))];

  glBindVertexArray(0);
  return coordBuffers;};
3
