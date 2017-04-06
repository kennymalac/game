layout (location=0) in vec4 in_Position;
layout (location=1) in vec4 in_UVx2;
uniform mat4 mvp;
uniform mat3 normalMatrix;
// controls the width and height
uniform float scaleXY;
// controls the height, heightmap values will be multiplied by scaleZ
uniform float scaleZ;
uniform float tesselationFactor;
uniform sampler2D heightMap;
uniform sampler2D tessellationMap;
// TODO lighting
//uniform sampler2D AmbientOcc
// TODO camera
uniform float tween;

attribute vec4 position;
attribute vec4 tweened;

void main() {
  // generate main grids
  // create patches on the grid
  // apply geomorphing
  // capture pivot tables
  // loop from one pivot to another pivot and cycle through terrain shader changes
  // declare pivot tables
  // decide where to place hills
  // elevation calculations for hills

  // calc all tweening
  gl_Position = m * ((1 - tween) * position + tween * tweened);

  return;
}
