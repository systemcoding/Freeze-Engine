#include "include/renderer/RenderCommands.h"

void RenderCommands::SetRenderColor(const glm::vec4& color)
{
    glClearColor(color.r, color.g, color.b, color.a);
}

void RenderCommands::RenderClear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}