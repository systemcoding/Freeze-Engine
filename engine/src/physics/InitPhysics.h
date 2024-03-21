#pragma once

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
            inline float MetersPerPixelFactor = 32.0f;

            inline b2Vec2 m_Gravity;
            inline b2World* m_PhysicsWorld;
            inline Box2DDebugRenderer* m_DebugRenderer;

            inline void InitPhysicsWorld()
            {
                m_Gravity = b2Vec2(0.0f, -10.0f);
                m_PhysicsWorld = new b2World(m_Gravity);

                FZ_INFO("Physics API Initialised");
                m_DebugRenderer = new Box2DDebugRenderer(MetersPerPixelFactor, b2Draw::e_shapeBit);
                m_PhysicsWorld->SetDebugDraw(m_DebugRenderer);
            }

            inline void UpdatePhysicsWorld(float dt)
            {
                float timeStep = 1.0 / 60.0f;

                int32 velocityIterations = 6;
                int32 positionIterations = 3; 

                m_PhysicsWorld->Step(timeStep, velocityIterations, positionIterations);

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