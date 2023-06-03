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
files {"../../engine/src/platform/linux/*.cpp", "../../engine/src/platform/linux/*.h", "../../engine/src/platform/linux/build_dir.h"}
files {"../../engine/src/platform/linux/root_dir.h"}

-- External Deps
files {"../../vendor/stb_image/stb_image.cpp"} -- stb_image
files {"../../vendor/imgui/*.cpp"} -- imgui
files {"../../vendor/imgui/backends/imgui_impl_glfw.cpp", "../../vendor/imgui/backends/imgui_impl_opengl3.cpp"}

prebuildcommands {'echo "inline const char* build_dir = \\"$(shell pwd)\\";" > ../../engine/src/platform/linux/build_path.h'}

-- Get the root directory of the actual project
local rootDir = path.getdirectory(path.getdirectory(debug.getinfo(1).source:sub(2)))
local parentDir = path.getdirectory(rootDir)

local outputFilePath = "../../engine/src/platform/linux/root_dir.h"  -- Adjust the file path as needed
local outputFile = io.open(outputFilePath, "w")
outputFile:write("#include <string>\n\n")
outputFile:write("inline std::string rootDir = \""  .. parentDir .. "/" .. "\";\n")
outputFile:close()

-- OpenGL
links {"GL"}

-- GLEW
links {"GLEW"}

-- GLFW
links {"glfw", "X11", "dl", "pthread"}

-- spdlog
includedirs {"../../vendor/spdlog/include"}

-- stb_image
includedirs {"../../vendor/stb_image/include"}

-- imgui
includedirs {"../../vendor/imgui"}

-- Engine files
includedirs {"../../engine/src/include"}

filter "configurations:Debug"
defines {"DEBUG"}
symbols "On"

filter "configurations:Release"
defines {"NDEBUG"}
optimize "On"