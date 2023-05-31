#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

namespace RenderCommands {
    void SetRenderColor(const glm::vec4& color);
    void RenderClear();
};