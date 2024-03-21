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

        void PhysicsBody::CreateDynamicPhysicsBody(const b2Vec2& size, const b2Vec2& positions, float density, float friction)
        {

            b2Vec2 bodySize = b2Vec2(size.x, size.y);
            b2Vec2 halfBodySize = b2Vec2(bodySize.x * 0.5f, bodySize.y * 0.5f);
            b2Vec2 bodyPosition = b2Vec2(positions.x, positions.y);

            m_BodyType = PHYBD_TYPES::DYNAMIC_BODY;
            m_DynamicPhysicsBodyData->m_DynamicPhysicsBodyQuad->CreateQuad(size.x, size.y, "", "");

            b2BodyDef dynamicBodyDef;
            dynamicBodyDef.type = b2_dynamicBody;
            dynamicBodyDef.position = PixelToMeter(bodyPosition);

            m_DynamicPhysicsBodyData->m_DynamicPhysicsBody = PhysicsModule::GetPhysicsWorld()->CreateBody(&dynamicBodyDef);

            b2PolygonShape dynamicBox;
            dynamicBox.SetAsBox(PixelToMeter(halfBodySize.x), PixelToMeter(halfBodySize.y), PixelToMeter(b2Vec2(0.0f, 0.0f)), 0.0f);

            b2FixtureDef fixtureDef;
            fixtureDef.shape = &dynamicBox;
            fixtureDef.density = density;
            fixtureDef.friction = friction;

            m_DynamicPhysicsBodyData->m_DynamicPhysicsBody->CreateFixture(&fixtureDef);

            m_DynamicBodies.push_back(m_DynamicPhysicsBodyData->m_DynamicPhysicsBody);
        }


        void PhysicsBody::CreateStaticPhysicsBody(const b2Vec2& size, const b2Vec2& positions)
        {
            b2Vec2 bodySize = b2Vec2(size.x, size.y);
            b2Vec2 halfBodySize = b2Vec2(bodySize.x * 0.5f, bodySize.y * 0.5f);
            b2Vec2 bodyPosition = b2Vec2(positions.x, positions.y);

            m_BodyType = PHYBD_TYPES::STATIC_BODY;
            m_StaticPhysicsBodyData->m_StaticPhysicsBodyQuad->CreateQuad(size.x, size.y, "", "");

            b2BodyDef staticBodyDef;
            staticBodyDef.type = b2_staticBody;
            staticBodyDef.position = PixelToMeter(bodyPosition);

            m_StaticPhysicsBodyData->m_StaticPhysicsBody = PhysicsModule::GetPhysicsWorld()->CreateBody(&staticBodyDef);

            b2PolygonShape staticBox;
            staticBox.SetAsBox(PixelToMeter(halfBodySize.x), PixelToMeter(halfBodySize.y), PixelToMeter(b2Vec2(0.0f, 0.0f)), 0.0f);  // Adjust shape based on half-size
            m_StaticPhysicsBodyData->m_StaticPhysicsBody->CreateFixture(&staticBox, 0.0f);

            m_StaticBodies.push_back(m_StaticPhysicsBodyData->m_StaticPhysicsBody);
        }

        b2Vec2 PhysicsBody::GetBodyPositions()
        {
            //TODO: NEED TO IMPLEMENT
        }

        void PhysicsBody::RenderPhysicsBody(const glm::mat4& projectionMatrix, const glm::vec4& color)
        {
            for(auto& dynBody : m_DynamicBodies)
            {
                m_DynamicPhysicsBodyData->m_DynamicBodyPos = dynBody->GetPosition();
                m_DynamicPhysicsBodyData->m_DynamicPhysicsBodyQuad->RenderQuad(projectionMatrix, { m_DynamicPhysicsBodyData->m_DynamicBodyPos.x,  m_DynamicPhysicsBodyData->m_DynamicBodyPos.y }, color);
                FZ_INFO("Coordinates: {}, {}", m_DynamicPhysicsBodyData->m_DynamicBodyPos.x, m_DynamicPhysicsBodyData->m_DynamicBodyPos.y);
            }

            for(auto& staticBody : m_StaticBodies)
            {
                m_StaticPhysicsBodyData->m_StaticBodyPos = staticBody->GetPosition();
                m_StaticPhysicsBodyData->m_StaticPhysicsBodyQuad->RenderQuad(projectionMatrix, { m_StaticPhysicsBodyData->m_StaticBodyPos.x, m_StaticPhysicsBodyData->m_StaticBodyPos.y }, color);
            }
        }

        PhysicsBody::~PhysicsBody()
        {
            delete m_DynamicPhysicsBodyData;
            delete m_StaticPhysicsBodyData;
        }
    };
};