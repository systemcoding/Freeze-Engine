#include "physics/PhysicsBody.h"

// TODO: API Looks like shit, needs some rework later!
// TODO: Looks like we need to seperate the dynamic body and static body implementations due to rendering issues. Dynamic could be converted into static and it's a mess!

namespace Freeze
{
    namespace Physics 
    {

        PhysicsBody::PhysicsBody()
        {
            InitStaticBody();
            InitDynamicBody();
        }

       void PhysicsBody::InitStaticBody()
        {
            m_StaticPhysicsBodyData = new StaticPhysicsBodyData();
        }

        void PhysicsBody::InitDynamicBody()
        {
            m_DynamicPhysicsBodyData = new DynamicPhysicsBodyData();
        }

        void PhysicsBody::CreateDynamicPhysicsBody(const glm::vec2& size, const glm::vec2& positions, float density, float friction)
        {
            m_BodyType = PHYBD_TYPES::DYNAMIC_BODY;
            FZ_INFO("DYNAMIC BODY");
            m_DynamicPhysicsBodyData->m_DynamicPhysicsBodyQuad->CreateQuad(size.x, size.y, "", "");

            b2BodyDef bodyDef;
            bodyDef.type = b2_dynamicBody;
            bodyDef.position.Set(positions.x, positions.y);
            m_DynamicPhysicsBodyData->m_DynamicPhysicsBody = PhysicsModule::GetPhysicsWorld()->CreateBody(&bodyDef);

            b2PolygonShape dynamicBox;
            dynamicBox.SetAsBox(size.x / 2, size.y / 2);
            b2FixtureDef fixtureDef;
            fixtureDef.shape = &dynamicBox;
            fixtureDef.density = density;
            fixtureDef.friction = friction;
            m_DynamicPhysicsBodyData->m_DynamicPhysicsBody->CreateFixture(&fixtureDef);

            m_DynamicBodies.push_back(m_DynamicPhysicsBodyData->m_DynamicPhysicsBody);
        }


        void PhysicsBody::CreateStaticPhysicsBody(const glm::vec2& size, const glm::vec2& positions)
        {
            m_BodyType = PHYBD_TYPES::STATIC_BODY;
            m_StaticPhysicsBodyData->m_StaticPhysicsBodyQuad->CreateQuad(size.x, size.y, "", "");

            b2BodyDef bodyDef;
            bodyDef.type = b2_staticBody;
            bodyDef.position.Set(positions.x, positions.y);
            m_StaticPhysicsBodyData->m_StaticPhysicsBody = PhysicsModule::GetPhysicsWorld()->CreateBody(&bodyDef);

            b2PolygonShape staticBox;
            staticBox.SetAsBox(size.x / 2, size.y / 2);  // Adjust shape based on half-size

            b2FixtureDef fixtureDef;
            fixtureDef.shape = &staticBox;
            m_StaticPhysicsBodyData->m_StaticPhysicsBody->CreateFixture(&fixtureDef);

            m_StaticBodies.push_back(m_StaticPhysicsBodyData->m_StaticPhysicsBody);
        }

        b2Vec2 PhysicsBody::GetBodyPositions()
        {
            //TODO: NEED TO IMPLEMENT
        }

        void PhysicsBody::RenderPhysicsBody(const glm::mat4& projectionMatrix, const glm::vec4& color)
        {
            if (m_BodyType == PHYBD_TYPES::DYNAMIC_BODY && m_DynamicPhysicsBodyData->m_DynamicPhysicsBody != nullptr)
            {
                for(auto& dynBody : m_DynamicBodies)
                {
                    m_DynamicPhysicsBodyData->m_DynamicBodyPos = dynBody->GetPosition();
                    m_DynamicPhysicsBodyData->m_DynamicPhysicsBodyQuad->RenderQuad(projectionMatrix, { m_DynamicPhysicsBodyData->m_DynamicBodyPos.x,  m_DynamicPhysicsBodyData->m_DynamicBodyPos.y }, color);
                    FZ_INFO("Positions: {}, {}", m_DynamicPhysicsBodyData->m_DynamicBodyPos.x, m_DynamicPhysicsBodyData->m_DynamicBodyPos.y);
                }
            }

            if (m_BodyType == PHYBD_TYPES::STATIC_BODY && m_StaticPhysicsBodyData->m_StaticPhysicsBody != nullptr)
            {
                for(auto& staticBody : m_StaticBodies)
                {
                    m_StaticPhysicsBodyData->m_StaticBodyPos = staticBody->GetPosition();
                    m_StaticPhysicsBodyData->m_StaticPhysicsBodyQuad->RenderQuad(projectionMatrix, { m_StaticPhysicsBodyData->m_StaticBodyPos.x, m_StaticPhysicsBodyData->m_StaticBodyPos.y }, color);
                    //FZ_INFO("Positions: {}, {}", m_StaticPhysicsBodyData->m_StaticBodyPos.x, m_StaticPhysicsBodyData->m_StaticBodyPos.y);
                }
            }
        }

        PhysicsBody::~PhysicsBody()
        {
            delete m_DynamicPhysicsBodyData;
            delete m_StaticPhysicsBodyData;
        }
    };
};