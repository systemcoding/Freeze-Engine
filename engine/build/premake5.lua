workspace "OpenGLEngine"
configurations {"Debug", "Release"}
platforms {"x64"}

project "OpenGLEngine"
kind "ConsoleApp"
language "C++"
targetdir "bin/%{cfg.buildcfg}"

files {"../src/*.cpp", "../src/include/**.h"}
files {"../../vendor/stb_image/stb_image.cpp"}

includedirs {"include"}

-- OpenGL
links {"GL"}

-- GLEW
links {"GLEW"}

-- GLFW
links {"glfw", "X11", "dl", "pthread"}

-- stb_image
includedirs {"../../vendor/stb_image/include"}

-- spdlog
includedirs {"../../vendor/spdlog/include"}

filter "configurations:Debug"
defines {"DEBUG"}
symbols "On"

filter "configurations:Release"
defines {"NDEBUG"}
optimize "On"
