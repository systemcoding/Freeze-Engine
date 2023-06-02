workspace "Sandbox"
configurations {"Debug", "Release"}
platforms {"x64"}

project "Sandbox"
kind "ConsoleApp"
language "C++"
targetdir "bin/%{cfg.buildcfg}"

files {"../src/*.cpp", "../src/**.h"}
files {"../../engine/src/*.cpp", "../../engine/src/include/*.h"}
files {"../../engine/src/platform/linux/*.cpp", "../../engine/src/platform/linux/*.h", "../../engine/src/platform/linux/build_dir.h"}

-- External Deps
files {"../../vendor/stb_image/stb_image.cpp"} -- stb_image
files {"../../vendor/imgui/*.cpp"} -- imgui
files {"../../vendor/imgui/backends/imgui_impl_glfw.cpp", "../../vendor/imgui/backends/imgui_impl_opengl3.cpp"}

prebuildcommands {'echo "static const char* build_dir = \\"$(shell pwd)\\";" > ../../engine/src/platform/linux/build_path.h'}

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
