#pragma once

#include <GLFW/glfw3.h>

#include <memory>

namespace Freeze {
    class KeyboardInput {
    public:
        KeyboardInput();

        static bool IsKeyPressed(GLFWwindow* window, int scancode);
        static bool IsKeyRepeated(GLFWwindow* window, int scancode);

        ~KeyboardInput();
    private:
    };
};
