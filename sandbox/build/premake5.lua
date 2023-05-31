workspace "Sandbox"
configurations {"Debug", "Release"}
platforms {"x64"}

project "Sandbox"
kind "ConsoleApp"
language "C++"
targetdir "bin/%{cfg.buildcfg}"

files {"../src/*.cpp", "../src/**.h"}
files {"../../vendor/stb_image/stb_image.cpp"}
files {"../../engine/src/*.cpp", "../../engine/src/include/*.h"}

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

-- Engine files
includedirs {"../../engine/src/include"}

filter "configurations:Debug"
defines {"DEBUG"}
symbols "On"

filter "configurations:Release"
defines {"NDEBUG"}
optimize "On"
