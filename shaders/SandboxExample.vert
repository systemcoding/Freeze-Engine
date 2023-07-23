#version 420 core

layout (location = 0) in vec3 a_Position;
layout (location = 1) in vec2 a_TextureCoords;

uniform mat4 a_ProjectionViewMat;
uniform mat4 a_ModelMatrix;

out vec2 o_TexCoords;

void main()
{
    gl_Position = a_ProjectionViewMat * a_ModelMatrix * vec4(a_Position, 1.0f);
    o_TexCoords = a_TextureCoords;
}