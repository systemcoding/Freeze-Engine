#pragma once

#include <box2d/box2d.h>

#include <cmath>
#include <memory>

#include "core/Core.h"

namespace Freeze
{
    namespace Physics {
        namespace PhysicsModule
        {
            inline b2Vec2 m_Gravity;
            inline std::shared_ptr<b2World> m_PhysicsWorld;

            inline void InitPhysicsWorld()
            {
                m_Gravity = b2Vec2(0.0f, -10.0f);
                m_PhysicsWorld = std::make_shared<b2World>(m_Gravity);

                FZ_INFO("Physics API Initialised");
            }

            inline void UpdatePhysicsWorld(float dt)
            {
                int32 velocityIterations = 9;
                int32 positionIterations = 3; 

                m_PhysicsWorld->Step(std::abs(m_Gravity.y) * dt, velocityIterations, positionIterations);
            }

            inline std::shared_ptr<b2World> GetPhysicsWorld() { return m_PhysicsWorld; }

        };
    };
};