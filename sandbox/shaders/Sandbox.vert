#version 420 core

layout (location = 0) in vec3 a_Position;

uniform mat4 a_ProjectionViewMatrix;

void main()
{
    gl_Position = a_ProjectionViewMatrix * vec4(a_Position, 1.0f);
}