#pragma once

#include <GL/glew.h>
#include <box2d/box2d.h>

class Box2DDebugRenderer : public b2Draw
{
public:
	Box2DDebugRenderer();
	Box2DDebugRenderer(const float MetersPerPixelFactor, const uint32_t DrawFlags);

	void DrawPolygon(const b2Vec2* pVertices, int32 VertexCount, const b2Color& rColor) override {};
	void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override;
	void DrawCircle(const b2Vec2& rCenter, float Radius, const b2Color& rColor) override {};
	void DrawSolidCircle(const b2Vec2& rCenter, float Radius, const b2Vec2& rAxis, const b2Color& rColor) override {};
	void DrawSegment(const b2Vec2& rPoint1, const b2Vec2& rPoint2, const b2Color& rColor) override {};
	void DrawTransform(const b2Transform& rTransform) override {};
	void DrawPoint(const b2Vec2& rPoint, float Size, const b2Color& rColor) override {};

	~Box2DDebugRenderer();
private:
	float MeterToPixel(const float Value);
	b2Vec2 MeterToPixel(const b2Vec2& rVector);

private:
	float m_MetersPerPixelFactor;
};