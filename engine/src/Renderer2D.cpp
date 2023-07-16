#include "include/renderer/Renderer2D.h"

namespace Freeze {
    void Renderer2D::Init()
    {
        // TODO: July 16th 2023, I Don't really have enough time now so i am going to leave the renderer2d like this!
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
};