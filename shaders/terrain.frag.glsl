in vec4 ex_Position;
in vec4 ex_UVx2;
out vec4 color;

uniform sampler2D grassTexture;
uniform sampler2D waterTexture;
uniform sampler2D dirtTexture;
uniform sampler2D sandTexture;
// uniform sampler2D textureN;

void main() {
    grass = texture(grassTexture, ex_UVx2.xy);

    // final output
    // TODO: texture based on height
    color = grass;

    return;
}
