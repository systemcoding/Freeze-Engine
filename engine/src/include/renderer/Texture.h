#pragma once

#include <GL/glew.h>
#include "stb_image.h"
#include <spdlog/spdlog.h>

#include <string>

namespace Freeze
{
    class Texture
    {
    public:
        Texture();

        void GenerateTexture(int nTextures, const std::string& filepath, GLint format);

        void BindTexture() const;
        void UnbindTexture() const;

        ~Texture();

    private:
        uint32_t m_TextureID;
        uint8_t* m_ImageData;
        int m_TextureWidth, m_TextureHeight, m_NTextureChannels;
    };
};