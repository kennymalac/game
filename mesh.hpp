#pragma once

struct Vertex {
  glm::vec3 position;
  glm::vec3 normal;
  glm::vec2 textureCoords;};

class RenderableMesh {
public:
  RenderableMesh(vector<Vertex> vertices, vector<Gluint> indices);

  inline void createCoordBuffer (vector<int> vertexarray, int stride) {
    glEnableVertexAttribArray(vertexAttribCount);
    glVertexAttribPointer(vertexAttribCount, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLVoid*)stride);
    vertexAttribCount++;
    return vertexAttribCount;}

  auto setupBuffers;
  void draw(ShaderProgram& shader);
private:
  GLuint VAO, VBO, EBO;
  std::vector<Vertex> vertices;
  int vertexAttribCount;}
