#pragma once

#include <GL/glew.h>
#include <box2d/box2d.h>

#include <memory>

#include "core/Core.h"
#include "physics/Box2DDebugRenderer.h"

namespace Freeze
{
    namespace Physics {
        namespace PhysicsModule
        {
            inline b2World* m_PhysicsWorld;
            inline Box2DDebugRenderer* m_DebugRenderer;

            inline void InitPhysicsWorld()
            {
                FZ_INFO("Physics API Initialised");

                b2Vec2 gravity(0.0f, -9.8f);

                m_PhysicsWorld = new b2World(gravity);
                m_DebugRenderer = new Box2DDebugRenderer(b2Draw::e_shapeBit);
                m_PhysicsWorld->SetDebugDraw(m_DebugRenderer);
            }


            inline void UpdatePhysicsWorld(float dt)
            {
                m_PhysicsWorld->Step(1.0f / 60.0f, 6, 3);
                m_PhysicsWorld->DebugDraw();
            }

            inline void CreatePhysicsBody()
            {
                // This is a test body, i'll remove it once some stuff is fixed!

                ///////////// Dynamic Body ///////////////////
                b2BodyDef dynBodyDef;
                dynBodyDef.type = b2_dynamicBody;
                dynBodyDef.position.Set(0.0f, 2.0f); // initial position of the box2d world

                b2Body* dynBody;
                dynBody = m_PhysicsWorld->CreateBody(&dynBodyDef);                

                // Define a shape for the body
                b2PolygonShape dynamicBox;
                dynamicBox.SetAsBox(0.1f, 0.1f);

                // Define fixture parameters
                b2FixtureDef dynFixtureDef;
                dynFixtureDef.shape = &dynamicBox;
                dynFixtureDef.density = 1.0f;
                dynFixtureDef.friction = 0.3f;

                // Attach the fixture to the body
                dynBody->CreateFixture(&dynFixtureDef);

                b2BodyDef dynBodyDef1;
                dynBodyDef1.type = b2_dynamicBody;
                dynBodyDef1.position.Set(0.0f, 2.0f); // initial position of the box2d world

                b2Body* dynBody1;
                dynBody1 = m_PhysicsWorld->CreateBody(&dynBodyDef1);                

                // Define a shape for the body
                b2PolygonShape dynamicBox1;
                dynamicBox1.SetAsBox(0.1f, 0.1f);

                // Define fixture parameters
                b2FixtureDef dynFixtureDef1;
                dynFixtureDef1.shape = &dynamicBox1;
                dynFixtureDef1.density = 1.0f;
                dynFixtureDef1.friction = 0.3f;
                dynFixtureDef1.restitution = 0.3f;

                // Attach the fixture to the body
                dynBody1->CreateFixture(&dynFixtureDef1);

                // ///////////////// Static Body //////////////////
                // b2BodyDef staticBodyDef;
                // staticBodyDef.type = b2_staticBody;
                // staticBodyDef.position.Set(0.0f, -0.7f);

                // b2Body* staticBody;
                // staticBody = m_PhysicsWorld->CreateBody(&staticBodyDef);

                // b2PolygonShape staticBox;
                // staticBox.SetAsBox(0.7f, 0.2f);

                // staticBody->CreateFixture(&staticBox, 0.0f);
            }

            inline b2World* GetPhysicsWorld() { return m_PhysicsWorld; }

            inline void DestroyPhysicsWorld()
            {
                delete m_DebugRenderer;
                
                m_PhysicsWorld->SetDebugDraw(nullptr);
                m_PhysicsWorld->ClearForces();

                delete m_PhysicsWorld;
            }
        };
    };
};