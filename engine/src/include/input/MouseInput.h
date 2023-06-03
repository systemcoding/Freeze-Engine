#pragma once

#include <GLFW/glfw3.h>

#include <array>

class MouseInput
{
public:
    MouseInput();

    static bool IsMousePressed(int scancode);

    // Debug
    static std::array<float, 2> GetMouseCoords();

    ~MouseInput();
private:
    float m_X, m_Y;
};