#version 420 core

layout (location = 0) in vec3 a_Position;

uniform mat4 a_ProjectionViewMat;

out vec3 a_ShapeCoords;

void main()
{
    gl_Position = a_ProjectionViewMat * vec4(a_Position, 1.0f);
    a_ShapeCoords = vec3(a_Position);
}