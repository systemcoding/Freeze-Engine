#pragma once

#include "box2d/b2_body.h"
#include "box2d/b2_polygon_shape.h"
#include "box2d/b2_fixture.h"

#include "core/Core.h"
#include "renderer/Renderer2D.h"
#include "InitPhysics.h"

#include <memory>

namespace Freeze {
  
  namespace Physics {

    class DynamicBody {
    public:

     DynamicBody();
     
     void CreateDynamicBody(const b2Vec2& size, const b2Vec2& positions, float friction, float density, float restitution);
     void RenderDynamicBody(const glm::mat4& projectionMatrix, const glm::vec4& color);
      
     b2Body* GetBody();
     
     const float GetFriction() const { return m_Friction; }
     const float GetDensity() const { return m_Density; }
     const float GetRestitution() const { return m_Restitution; }
     
     ~DynamicBody();

    public:

      struct DynamicBodyData {
       b2Body* Body = nullptr;
       b2BodyDef BodyDef;
       b2PolygonShape Shape;
       b2FixtureDef FixtureDef;
       
       std::shared_ptr<FreezeQuad> m_Quad;
     };
    
    private:
      DynamicBodyData* m_BodyData;
      
      b2Vec2 m_Positions;
      b2Vec2 m_Size;
      
      float m_Density;
      float m_Friction;
      float m_Restitution;
    };

    class StaticBody {
    public:
     StaticBody();
     
     void CreateStaticBody(const b2Vec2& size, const b2Vec2& positions);
     void RenderStaticBody(const glm::mat4& projectionMatrix, const glm::vec4& color);
      
     b2Body* GetBody();
     
     ~StaticBody();
    public:

      struct StaticBodyData {
       b2Body* Body = nullptr;
       b2BodyDef BodyDef;
       b2PolygonShape Shape;
       b2FixtureDef FixtureDef;
       
       std::shared_ptr<FreezeQuad> m_Quad;
     };
    
    private:
      StaticBodyData* m_BodyData;
      
      b2Vec2 m_Positions;
      b2Vec2 m_Size;
    };

  };

};
