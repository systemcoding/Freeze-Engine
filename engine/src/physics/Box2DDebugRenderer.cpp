#include "Box2DDebugRenderer.h"

#include <vector>

Box2DDebugRenderer::Box2DDebugRenderer()
    :m_MetersPerPixelFactor(0.0f)
{

}

Box2DDebugRenderer::Box2DDebugRenderer(const float MetersPerPixelFactor, const uint32_t DrawFlags)
    :m_MetersPerPixelFactor(MetersPerPixelFactor)
{
	SetFlags(DrawFlags);
}


void Box2DDebugRenderer::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) 
{
    GLfloat glverts[16]; //allow for polygons up to 8 vertices
    glVertexPointer(2, GL_FLOAT, 0, glverts); //tell OpenGL where to find vertices
    glEnableClientState(GL_VERTEX_ARRAY); //use vertices in subsequent calls to glDrawArrays
    
    //fill in vertex positions as directed by Box2D
    for (int i = 0; i < vertexCount; i++) {
      glverts[i*2]   = vertices[i].x;
      glverts[i*2+1] = vertices[i].y;
    }
    
    //draw solid area
    glColor4f( color.r, color.g, color.b, 1);
    glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);
  
    //draw lines
    glLineWidth(3); //fat lines
    glColor4f( 1, 0, 1, 1 ); //purple
    glDrawArrays(GL_LINE_LOOP, 0, vertexCount);
}


float Box2DDebugRenderer::MeterToPixel(const float Value)
{
	return (Value * m_MetersPerPixelFactor);
}

b2Vec2 Box2DDebugRenderer::MeterToPixel(const b2Vec2& rVector)
{
	return b2Vec2(MeterToPixel(rVector.x), MeterToPixel(rVector.y));
}

Box2DDebugRenderer::~Box2DDebugRenderer()
{

}