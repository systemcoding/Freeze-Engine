workspace "Sandbox"
configurations {"Debug", "Release"}
platforms {"x64"}
cppdialect "C++17"

project "Sandbox"
kind "ConsoleApp"
language "C++"
targetdir "bin/%{cfg.buildcfg}"

files {"../src/*.cpp", "../src/**.h"}
files {"../../engine/src/*.cpp", "../../engine/src/include/*.h"}

-- External Deps
files {"../../external/imgui/*.cpp"} -- imgui
files {"../../external/imgui/backends/imgui_impl_glfw.cpp", "../../external/imgui/backends/imgui_impl_opengl3.cpp"}

-- Get the root directory of the actual project
local rootDir = path.getdirectory(path.getdirectory(debug.getinfo(1).source:sub(2)))
local parentDir = path.getdirectory(rootDir)

local outputFilePath = "../../engine/src/include/core/root_dir.h" -- Adjust the file path as needed
local outputFile = io.open(outputFilePath, "w")
outputFile:write("#pragma once\n\n")
outputFile:write("#include <string>\n\n")
outputFile:write("inline std::string rootDir = \"" .. parentDir .. "/" .. "\";\n")
outputFile:close()

-- OpenGL
links {"GL"}

-- GLEW
links {"GLEW"}

-- GLFW
links {"glfw", "X11", "dl", "pthread"}

-- spdlog
includedirs {"../../external/spdlog/include"}

-- stb_image
includedirs {"../../external/stb_image/include"}

-- imgui
includedirs {"../../external/imgui"}

-- glm
includedirs {"../../external/glm/"}

-- ImGuiFileDialog
includedirs {"../../external/ImGuiFileDialog/"}

-- Engine files
includedirs {"../../engine/src/include"}

filter "configurations:Debug"
defines {"DEBUG"}
symbols "On"

filter "configurations:Release"
defines {"NDEBUG"}
optimize "On"
