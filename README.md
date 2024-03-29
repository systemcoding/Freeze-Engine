# Freeze Engine
Freeze Engine - A Small Game Engine Made Using C++ and OpenGL

### Small Update: The physics implementation of this branch is really bad, please check the debug branch for physics-only purposes. It's a testing branch.

## How To Run?
This engine only supports linux for now (I will extend this to windows and etc...). If you are running Linux make sure you have:
- glew
- glfw
- opengl
- cmake
Other dependencies will be taken care by the premake5.

### C++ LSP Neovim Issue:
If you are using neovim (or any other editor with clang lsp server) as your editor and you have clangd server enabled then follow these steps:
```bash
git clone https://github.com/systemcoding/Freeze-Engine
cd Freeze-Engine
mkdir build
cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
cmake --build . -j5
./bin/Sandbox
```
For debugging: `cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..`

Since the clangd lsp server requires the compile_commands.json for finding header files and correct linking use the above commands.

Instructions: (Not For Neovim LSP Users!!!)
```bash
git clone --recursive https://github.com/systemcoding/Freeze-Engine
cd Freeze-Engine/
mkdir build
cmake ..
make -j5
./bin/Sandbox
```
Also for debugging, compile with this: `cmake -DCMAKE_BUILD_TYPE=Debug ..`

Some default keybindings:
```
Move Left - A
Move Right - D
Move Camera Left - Page Down
Move Camera Right - Page Up
```

That's it! Now you can open up and edit `sandbox/src/Sandbox.cpp` to your liking!

### 10-09-2023 Update:
[2023-09-10 20-20-57.webm](https://github.com/systemcoding/Freeze-Engine/assets/68456596/88893803-050e-49c7-b4d1-866043e30816)

### 23-07-2023 Update:
[Freeze Engine New Demo](https://github.com/systemcoding/Freeze-Engine/assets/68456596/e78ff5b2-5af8-4fd2-a541-96592d109fc7)

### 31-05-2023 Update:
[Freeze Engine Demo](https://github.com/systemcoding/Freeze-Engine/assets/68456596/a3a84e00-75a4-4fd8-9b45-eccefe8fbfef)

