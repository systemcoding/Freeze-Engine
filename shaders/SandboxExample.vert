#version 420 core

layout (location = 0) in vec3 a_Position;
layout (location = 1) in vec3 a_Color;
layout (location = 2) in vec2 a_TexCoords;

out vec3 triangleColor;
out vec2 textureCoords;

uniform mat4 transMatrix;

void main()
{
    gl_Position = transMatrix * vec4(a_Position, 1.0f);
    triangleColor = a_Color;
    textureCoords = a_TexCoords;
}