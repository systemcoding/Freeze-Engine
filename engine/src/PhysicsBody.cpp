#include "physics/PhysicsBody.h"

namespace Freeze
{
    namespace Physics 
    {
        void PhysicsBody::CreatePhysicsBody(b2BodyType bodyType, const glm::vec2& size, const glm::vec2& positions, float density, float friction)
        {
            m_Quad->CreateQuad(size.x, size.y, "", "");

            b2BodyDef bodyDef;
            bodyDef.type = bodyType;
            bodyDef.position.Set(positions.x, positions.y);
            m_PhysicsBody = PhysicsModule::GetPhysicsWorld()->CreateBody(&bodyDef);

            b2PolygonShape dynamicBox;
            dynamicBox.SetAsBox(1.0f, 1.0f);
            b2FixtureDef fixtureDef;
            fixtureDef.shape = &dynamicBox;
            fixtureDef.density = density;
            fixtureDef.friction = friction;
            m_PhysicsBody->CreateFixture(&fixtureDef); 
        }

        void PhysicsBody::RenderPhysicsBody(const glm::mat4& projectionMatrix)
        {
            b2Vec2 positions = m_PhysicsBody->GetPosition();
            m_Quad->DrawQuad(projectionMatrix, { positions.x, positions.y }, { 0.2f, 0.1f, 0.4f, 0.5f });
        }

        PhysicsBody::~PhysicsBody()
        {

        }
    };
};