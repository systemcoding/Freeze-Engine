#include "Box2DDebugRenderer.h"

namespace Freeze {

    Box2DDebugRenderer::Box2DDebugRenderer()
        : m_MetersPerPixelFactor(0.0f)
    {
    }

    Box2DDebugRenderer::Box2DDebugRenderer(const float MetersPerPixelFactor, const uint32_t DrawFlags)
        : m_MetersPerPixelFactor(MetersPerPixelFactor)
    {
        SetFlags(DrawFlags);
    }

    void Box2DDebugRenderer::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) 
    {
        FZ_INFO("DEBUG RENDER: Rendering solid polygon with: {} vertices", vertexCount);
        glColor4f(color.r, color.g, color.b, 1.0f); // Use the provided color

        // Render the solid polygon
        glBegin(GL_TRIANGLE_FAN);
        for (int32 i = 0; i < vertexCount; ++i) {
            glVertex2f(vertices[i].x, vertices[i].y);
        }
        glEnd();
    }

    Box2DDebugRenderer::~Box2DDebugRenderer() {}
};