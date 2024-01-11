#pragma once

#include <box2d/box2d.h>

#include <memory>

#include "core/Core.h"
#include "renderer/Renderer2D.h"
#include "InitPhysics.h"

namespace Freeze {

    namespace Physics {
        class PhysicsBody {
        public:
        public:
            PhysicsBody() = default;

            void CreatePhysicsBody(b2BodyType bodyType, const glm::vec2& size, const glm::vec2& positions, float density, float friction);

            void RenderPhysicsBody(const glm::mat4& projectionMatrix);

            b2Vec2 GetBodyPositions() { return m_PhysicsBody->GetPosition(); }

            ~PhysicsBody();
        private:
            b2Body* m_PhysicsBody; 
            std::shared_ptr<Freeze::FreezeQuad> m_Quad = std::make_shared<Freeze::FreezeQuad>();

        };
    };

};