#include "engine/EngineWindow.h"
#include "spdlog/spdlog.h"

int main()
{
    spdlog::info("Engine Running!");

    EngineWindow* engineWindow = new EngineWindow(800, 600, "OpenGL Engine");
    delete engineWindow;
}