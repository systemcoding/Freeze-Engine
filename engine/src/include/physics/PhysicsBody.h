#pragma once

#include <box2d/box2d.h>

#include <memory>

#include "core/Core.h"
#include "renderer/Renderer2D.h"
#include "InitPhysics.h"

namespace Freeze {
    namespace Physics {
        class PhysicsBody {
        private:
            struct StaticPhysicsBodyData
            {
                b2Body* m_StaticPhysicsBody = nullptr;
                std::shared_ptr<Freeze::FreezeQuad> m_StaticPhysicsBodyQuad = std::make_shared<Freeze::FreezeQuad>();
            };

            struct DynamicPhysicsBodyData
            {
                b2Body* m_DynamicPhysicsBody = nullptr;
                std::shared_ptr<Freeze::FreezeQuad> m_DynamicPhysicsBodyQuad = std::make_shared<Freeze::FreezeQuad>();

                float density, friction;
            };

            enum class PHYBD_TYPES 
            {
                NONE = 0,
                STATIC_BODY, DYNAMIC_BODY
            };

        public:
            PhysicsBody();

            void InitStaticBody();
            void InitDynamicBody();

            void CreateDynamicPhysicsBody(const glm::vec2& size, const glm::vec2& positions, float density, float friction);
            void CreateStaticPhysicsBody(const glm::vec2& size, const glm::vec2& positions);

            void RenderPhysicsBody(const glm::mat4& projectionMatrix, const glm::vec4& color);

            b2Vec2 GetBodyPositions();

            ~PhysicsBody();
        private:
            StaticPhysicsBodyData* m_StaticPhysicsBodyData;
            DynamicPhysicsBodyData* m_DynamicPhysicsBodyData;

            PHYBD_TYPES m_BodyType = PHYBD_TYPES::NONE;
        };
    };
};