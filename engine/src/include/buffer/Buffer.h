#pragma once

#include <GL/glew.h>

#include "spdlog/spdlog.h"

#include <cstdint>

namespace Freeze {
    class VertexBuffer 
    {
    public:
        VertexBuffer() = default;

        void AddVertexBuffer(int nBuffers, float* data, uint32_t size, GLenum drawType);

        void BindVertexBuffer() const;
        void UnbindVertexBuffer() const;

        ~VertexBuffer();
    private:
        uint32_t m_VertexBufferObjectID;
        int m_NVertexBuffers;
    };

    class ElementBuffer
    {
    public:
        ElementBuffer() = default;

        void AddElementBuffer(int nBuffers, uint32_t* data, uint32_t size, GLenum drawType);

        void BindElementBuffer() const;
        void UnbindElementBuffer() const;

        ~ElementBuffer();
    private:
        uint32_t m_ElementBufferObjectID;
        int m_NElementBuffers;
    };
};