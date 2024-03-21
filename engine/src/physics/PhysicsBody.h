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
                b2Vec2 m_StaticBodyPos = {};
                std::shared_ptr<Freeze::FreezeQuad> m_StaticPhysicsBodyQuad = std::make_shared<Freeze::FreezeQuad>();
            };

            struct DynamicPhysicsBodyData
            {
                b2Body* m_DynamicPhysicsBody = nullptr;
                b2Vec2 m_DynamicBodyPos = {};
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

            void CreateDynamicPhysicsBody(const b2Vec2& size, const b2Vec2& positions, float density, float friction);
            void CreateStaticPhysicsBody(const b2Vec2& size, const b2Vec2& positions);

            void RenderPhysicsBody(const glm::mat4& projectionMatrix, const glm::vec4& color);

            b2Vec2 GetBodyPositions();

            ~PhysicsBody();

        private:
            // Unit conversion functions (CREDIT: https://discourse.libsdl.org/t/initializing-box2d-into-sdl/49047/8)
            float PixelToMeter(const float value) { return (value * (1.0f / MetersPerPixelFactor)); }
            b2Vec2 PixelToMeter(const b2Vec2& vector) { return b2Vec2(PixelToMeter(vector.x), PixelToMeter(vector.y)); }

            float MeterToPixel(const float value) { return (value * MetersPerPixelFactor); }
            b2Vec2 MeterToPixel(const b2Vec2& vector) { return b2Vec2(MeterToPixel(vector.x), MeterToPixel(vector.y)); }

        private:
            StaticPhysicsBodyData* m_StaticPhysicsBodyData;
            DynamicPhysicsBodyData* m_DynamicPhysicsBodyData;

            PHYBD_TYPES m_BodyType = PHYBD_TYPES::NONE;

            std::vector<b2Body*> m_DynamicBodies;
            std::vector<b2Body*> m_StaticBodies;
            const float MetersPerPixelFactor = 32.0f;
        };
    };
};