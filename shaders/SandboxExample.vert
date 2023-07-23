#version 420 core

layout (location = 0) in vec4 a_Position; // We will bring the entire position data as vec4 and split it into vec2 for texture coordinates and vec2 for positions

uniform mat4 a_ProjectionViewMat;
uniform mat4 a_ModelMatrix;

out vec2 o_TexCoords;

void main()
{
    o_TexCoords = a_Position.zw; // .zw because we want to access the last 2 coordinates from the vec4
    gl_Position = a_ProjectionViewMat * a_ModelMatrix * vec4(a_Position.xy, 0.0f, 1.0f); // same goes here instead we use .xy to access the first 2 coordinates
}