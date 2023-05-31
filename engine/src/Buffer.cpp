#include "include/buffer/Buffer.h"

namespace Freeze {

    /////////////////////////////////// Vertex Buffer ///////////////////////////////////////////

    void VertexBuffer::AddVertexBuffer(int nBuffers, float* data, uint32_t size, GLenum drawType)
    {
        m_NVertexBuffers = nBuffers;
        glGenBuffers(1, &m_VertexBufferObjectID);
        glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferObjectID);
        glBufferData(GL_ARRAY_BUFFER, size, data, drawType);

        if(data == nullptr || m_NVertexBuffers == 0)
        {
            spdlog::error("Vertex Buffer: No Data/Invalid Data Provided or No Of Buffers is 0!");
            exit(0);
        }
    }

    void VertexBuffer::BindVertexBuffer() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferObjectID);
    }

    void VertexBuffer::UnbindVertexBuffer() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    VertexBuffer::~VertexBuffer()
    {
        spdlog::info("Freed Vertex Buffers: {}", m_NVertexBuffers);
        glDeleteBuffers(m_NVertexBuffers, &m_VertexBufferObjectID);
    }

    ///////////////////////////////// Element Buffer //////////////////////////////////////

    void ElementBuffer::AddElementBuffer(int nBuffers, uint32_t* data, uint32_t size, GLenum drawType)
    {
        m_NElementBuffers = nBuffers;
        glGenBuffers(m_NElementBuffers, &m_ElementBufferObjectID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ElementBufferObjectID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, drawType);

        if(data == nullptr || m_NElementBuffers == 0)
        {
            spdlog::error("Element Buffer: No Data/Invalid Data Provided or No Of Buffers is 0!");
            exit(0);
        }
    }

    void ElementBuffer::BindElementBuffer() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ElementBufferObjectID);
    }

    void ElementBuffer::UnbindElementBuffer() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    ElementBuffer::~ElementBuffer()
    {
        spdlog::info("Freed Element Buffers: {}", m_NElementBuffers);
        glDeleteBuffers(m_NElementBuffers, &m_ElementBufferObjectID);
    }
};