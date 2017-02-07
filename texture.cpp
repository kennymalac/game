auto createFrameBuffer(int length) {
  GLuint frameBufferId = frameBufferCount++;
  glGenFrameBuffers(length, &frameBufferId);
  glBindFramebuffer(GL_FRAMEBUFFER, frameBufferId);
}

// Texture2D:Texture2D () {
  
// }

Texture::Texture (auto color) {
  GLuint texture;
  // WARNING: Hardcoded ID!!!
  // HARDCODED limit of 1 texture
  glGenTextures(1, &texture);
  glBindTexture(typeId, texture);
  return GL_TEXTURE1;
}

