#pragma once

#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

class KeyboardEvent {
public:
    KeyboardEvent();

    bool GetKey(int keycode);

    ~KeyboardEvent();
private:
};