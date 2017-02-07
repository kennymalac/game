#pragma once

class RenderableMesh {
public:
  RenderableMesh(vector<Vertex> vertices, vector<Gluint> indices);

  inline void createCoordBuffer (auto vertexarray, int stride) {
    glEnableVertexAttribArray(vertexAttribCount);
    glVertexAttribPointer(vertexAttribCount, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLVoid*)stride);
    vertexAttribCount++;
    return vertexAttribCount;}

  auto setupBuffers;
  void draw(ShaderProgram& shader);
private:
  GLuint VAO, VBO, EBO;
  auto vertices;
  int vertexAttribCount;}
