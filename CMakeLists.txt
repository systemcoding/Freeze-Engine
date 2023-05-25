# Projects Settings
cmake_minimum_required (VERSION 3.16)
project (opengl-engine LANGUAGES CXX)
cmake_policy(SET CMP0072 NEW)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(spdlog REQUIRED)

add_executable(opengl-engine
  src/Application.cpp

  # Engine Implementations
  src/engine/EngineWindow.cpp
  src/engine/Shader.cpp
  src/engine/RenderCommands.cpp
  src/engine/Texture.cpp

  src/engine-testing/RenderTriangle.cpp
  
  # External libraries (vendor)
  vendor/stb_image/stb_image.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/vendor/stb-image)
include_directories(${CMAKE_SOURCE_DIR}/vendor/glm)

target_link_libraries(opengl-engine
  glfw
  GLEW
  OpenGL::GL
  spdlog::spdlog $<$<BOOL:${gcc}>:ws2_32>
)