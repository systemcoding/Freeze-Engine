#version 420 core

out vec4 o_QuadColor;

uniform vec4 a_Color;

void main()
{
    o_QuadColor = vec4(a_Color);
}