#version 420 core

layout (location = 0) in vec3 a_PlayerPos;

uniform mat4 a_ProjectionMatrix;
uniform mat4 a_InputMatrix;

void main()
{
    vec4 transformedPosition = a_ProjectionMatrix * a_InputMatrix * vec4(a_PlayerPos, 1.0f);
    gl_Position = transformedPosition;
}