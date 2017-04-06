#pragma once
#include <map>
struct Texture;

class RenderableMesh {
public:
  RenderableMesh(vector<Vertex>& vertices, vector<Gluint>& indices, vector<Texture>& textures);

  inline void createCoordBuffer (auto vertexarray, int stride) {
    glEnableVertexAttribArray(vertexAttributeCount);
    glVertexAttribPointer(vertexAttributeCount, GL_FLOAT, GL_FALSE, sizeof(Pos), (GLVoid*)stride);
    vertexAttributeCount++;
    return vertexAttributeCount;};

  auto setupBuffers;
  void draw();
private:
  GLuint VAO, VBO, EBO;
  std::vector<Vector>& vertices;
  std::vector<unsigned int>& indices;
  std::vector<Texture>& textures;
  int vertexAttributeCount;};
