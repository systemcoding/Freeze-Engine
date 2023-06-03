#version 420 core

out vec4 f_TColor;

in vec3 triangleColor;
in vec2 textureCoords;

uniform sampler2D tex0;

void main()
{
    f_TColor = texture(tex0, textureCoords);
}