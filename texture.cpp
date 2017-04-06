auto createFrameBuffer(int length) {
  // untested
  GLuint frameBufferId = frameBufferCount++;
  glGenFrameBuffers(length, &frameBufferId);
  glBindFramebuffer(GL_FRAMEBUFFER, frameBufferId);
};

// Texture2D:Texture2D () {
  
// }

auto renderTextureToFrameBuffer(Texture& t) {
  GLuint FBO;
  glGenFramebuffers(1, &FBO);
  glBindFramebuffer(GL_FRAMEBUFFER, FBO);

  // TODO render to Texture3D as well
  glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, &t->dimension, &t->textureId, 0);
  return FBO;
};

auto allocateTextureNames (std::vector<Texture>& textures) {
  //whut whut
  auto names = glGenTextures(n, textureNames);

  for (auto t : textures.begin()) {
    t.textureId = names.pop();}

  // Later this will be useful for pushing them to the GPU all at once
  return &textureNames;};

auto bindTextures (auto& textures) {
  for (auto& texture : textures) {
    // Retrieve the current index in the vector
    glActiveTexture(GL_TEXTURE0 + (&texture - this->textures[0]));
    glUniform1f(texture->uniformLocation, texture->name);
    glBindTexture(texture->dimension, texture->id);}

  // Go back to the initial texture
  glActiveTexture(GL_TEXTURE0);};

Texture::Texture () {
  // GlGenTextures moved to allocateTextureNames
};



