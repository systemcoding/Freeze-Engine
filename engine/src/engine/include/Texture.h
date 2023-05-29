#pragma once

#include <GL/glew.h>
#include "stb/stb_image.h"
#include <spdlog/spdlog.h>

#include <string>

class Texture {
public:
    Texture();

    void generateTexture(int nTextures, const std::string& filepath, GLint format);

    void bindTexture() const;
    void unbindTexture() const;

    ~Texture();
private:
    uint32_t m_TextureID;
    uint8_t* m_ImageData;
    int m_TextureWidth, m_TextureHeight, m_NTextureChannels;
};