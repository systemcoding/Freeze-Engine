#include "PhysicsBody.h"

namespace Freeze {

  namespace Physics {
    
    ////////////////////// DYNAMIC BODY ///////////////////////
    DynamicBody::DynamicBody()
      :m_BodyData(new DynamicBodyData())
    {
    }

    void DynamicBody::CreateDynamicBody(const b2Vec2& size, const b2Vec2& positions, float density, float friction, float restitution)
    {
       m_Size = b2Vec2(size.x, size.y);
       b2Vec2 halfBodySize = b2Vec2(m_Size.x * 0.5f, m_Size.y * 0.5f);
       m_Positions = b2Vec2(positions.x, positions.y);
       
       m_BodyData->m_Quad = std::make_shared<FreezeQuad>();  
       m_BodyData->m_Quad->CreateQuad(size.x, size.y, "", "");

       m_BodyData->BodyDef.type = b2_dynamicBody;
       m_BodyData->BodyDef.position = PixelToMeter(m_Positions);
      
       m_BodyData->Body = PhysicsModule::GetPhysicsWorld()->CreateBody(&m_BodyData->BodyDef);
      
       m_BodyData->Shape.SetAsBox(PixelToMeter(halfBodySize.x), PixelToMeter(halfBodySize.y));

       m_BodyData->FixtureDef.shape = &m_BodyData->Shape;
       m_BodyData->FixtureDef.density = density;
       m_Density = density;
       
       m_BodyData->FixtureDef.friction = friction;
       m_Friction = friction;
       
       m_BodyData->FixtureDef.restitution = restitution;
       m_Restitution = restitution;
      
       m_BodyData->Body->CreateFixture(&m_BodyData->FixtureDef);
    }
    
    void DynamicBody::RenderDynamicBody(const glm::mat4& projectionMatrix, const glm::vec4& color)
    {

    }

    DynamicBody::~DynamicBody()
    {
      delete m_BodyData;
    }
    

    /////////////////////// STATIC BODY ////////////////////
    StaticBody::StaticBody()
      :m_BodyData(new StaticBodyData())
    {
    }

    void StaticBody::CreateStaticBody(const b2Vec2& size, const b2Vec2& positions)
    {
       m_Size = b2Vec2(size.x, size.y);
       b2Vec2 halfBodySize = b2Vec2(m_Size.x * 0.5f, m_Size.y * 0.5f);
       m_Positions = b2Vec2(positions.x, positions.y);
       
       m_BodyData->m_Quad = std::make_shared<FreezeQuad>();  
       m_BodyData->m_Quad->CreateQuad(size.x, size.y, "", "");

       m_BodyData->BodyDef.type = b2_staticBody;
       m_BodyData->BodyDef.position = PixelToMeter(m_Positions);
      
       m_BodyData->Body = PhysicsModule::GetPhysicsWorld()->CreateBody(&m_BodyData->BodyDef);
       m_BodyData->Shape.SetAsBox(PixelToMeter(halfBodySize.x), PixelToMeter(halfBodySize.y), PixelToMeter(b2Vec2(0.0f, 0.0f)), 0.0f);

       m_BodyData->Body->CreateFixture(&m_BodyData->Shape, 0.0f);
    }

    void StaticBody::RenderStaticBody(const glm::mat4& projectionMatrix, const glm::vec4& color)
    {

    }

    StaticBody::~StaticBody()
    {
      delete m_BodyData;
    }


  }

}
