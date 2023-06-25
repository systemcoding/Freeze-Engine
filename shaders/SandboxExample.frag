#version 420 core

out vec4 f_TColor;
in vec3 triangleColor;

void main()
{
    f_TColor = vec4(triangleColor, 1.0f);
}