#include "physics/PhysicsBody.h"

namespace Freeze
{
    namespace Physics 
    {
        void PhysicsBody::CreateDynamicPhysicsBody(const glm::vec2& size, const glm::vec2& positions, float density, float friction)
        {
            FZ_INFO("BODY CREATED! and positions: {}, {}", positions.x, positions.y);
            m_PhysicsBodyData->m_PhysicsBodyQuad->CreateQuad(size.x, size.y, "", "");

            b2BodyDef bodyDef;
            bodyDef.type = b2_dynamicBody;
            bodyDef.position.Set(positions.x, positions.y);
            m_PhysicsBodyData->m_PhysicsBody = PhysicsModule::GetPhysicsWorld()->CreateBody(&bodyDef);

            b2PolygonShape dynamicBox;
            dynamicBox.SetAsBox(size.x / 2.0f, size.y / 2.0f);
            b2FixtureDef fixtureDef;
            fixtureDef.shape = &dynamicBox;
            fixtureDef.density = density;
            fixtureDef.friction = friction;
            m_PhysicsBodyData->m_PhysicsBody->CreateFixture(&fixtureDef); 
        }


        void PhysicsBody::CreateStaticPhysicsBody(const glm::vec2& size, const glm::vec2& positions)
        {
            m_PhysicsBodyData->m_PhysicsBodyQuad->CreateQuad(size.x, size.y, "", "");

            b2BodyDef bodyDef;
            bodyDef.type = b2_staticBody;
            bodyDef.position.Set(positions.x, positions.y);
            m_PhysicsBodyData->m_PhysicsBody = PhysicsModule::GetPhysicsWorld()->CreateBody(&bodyDef);

            b2PolygonShape staticBox;
            staticBox.SetAsBox(size.x / 2.0f, size.y / 2.0f);  // Adjust shape based on half-size
            b2FixtureDef fixtureDef;
            fixtureDef.shape = &staticBox;
            fixtureDef.density = 0.0f;  // No need to set density for static bodies
            m_PhysicsBodyData->m_PhysicsBody->CreateFixture(&fixtureDef);
        }

        void PhysicsBody::RenderPhysicsBody(const glm::mat4& projectionMatrix, const glm::vec4& color)
        {
            b2Vec2 positions = m_PhysicsBodyData->m_PhysicsBody->GetPosition();

            m_PhysicsBodyData->m_PhysicsBodyQuad->RenderQuad(projectionMatrix, { positions.x, positions.y }, color);
            FZ_INFO("BODY RENDERED! and positions: {}, {}", positions.x, positions.y);
        }

        PhysicsBody::~PhysicsBody()
        {
            delete m_PhysicsBodyData;
        }
    };
};