#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

namespace RenderCommands {
    void SetRenderColor(glm::vec4& color);
    void RenderClear();
};