#pragma once

#include <GL/glew.h>
#include <box2d/box2d.h>

#include <cmath>
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

            inline b2Body* m_Body;

            inline void InitPhysicsWorld()
            {
                FZ_INFO("Physics API Initialised");

                b2Vec2 gravity(0.0f, -9.8f);

                m_PhysicsWorld = new b2World(gravity);
                m_DebugRenderer = new Box2DDebugRenderer(32.0f, b2Draw::e_shapeBit);
                m_PhysicsWorld->SetDebugDraw(m_DebugRenderer);
            }

            inline void CreatePhysicsBody()
            {
                // This is a test body, i'll remove it once some stuff is fixed!
                b2BodyDef bodyDef;
                bodyDef.type = b2_dynamicBody;
                bodyDef.position.Set(0.0f, 0.0f); // initial position
                m_Body = m_PhysicsWorld->CreateBody(&bodyDef);

                // Define a shape for the body
                b2PolygonShape dynamicBox;
                dynamicBox.SetAsBox(0.2f, 0.2f);

                // Define fixture parameters
                b2FixtureDef fixtureDef;
                fixtureDef.shape = &dynamicBox;
                fixtureDef.density = 1.0f;
                fixtureDef.friction = 0.3f;

                // Attach the fixture to the body
                m_Body->CreateFixture(&fixtureDef); 
            }

            inline void UpdatePhysicsWorld()
            {
                m_PhysicsWorld->Step(1.0f / 60.0f, 6, 3);
                m_PhysicsWorld->DebugDraw();
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