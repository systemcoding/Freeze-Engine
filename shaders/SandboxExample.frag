#version 420 core

uniform sampler2D ourTexture;

in vec2 o_TexCoords;
out vec4 o_FragColor;

void main()
{
    o_FragColor = texture(ourTexture, o_TexCoords);
}