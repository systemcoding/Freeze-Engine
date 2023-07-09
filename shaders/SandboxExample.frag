#version 420 core

in vec3 a_ShapeCoords;
out vec4 f_Color;

void main()
{
    f_Color = vec4(a_ShapeCoords, 0.3f);
}