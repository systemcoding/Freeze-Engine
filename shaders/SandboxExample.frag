#version 420 core

uniform sampler2D ourTexture;
uniform vec3 spriteColor;

in vec2 o_TexCoords;
out vec4 o_FragColor;

void main()
{
    o_FragColor = vec4(spriteColor, 1.0f) * texture(ourTexture, o_TexCoords);
}