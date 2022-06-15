# BasedGUI rendering framework
`BasedGUI` is an OpenGL rendering framework.<br>

## Setup
Make sure to set the env variables `CXX_COMPILER` and `C_COMPILER` to your respective c++ and c compilers.<br>
Then install the dependencies listed below into the `libs` folder.<br>
Then simply execute the `setup.sh`, which will generate the XCode or Visual Studio project.<br>

## Dependencies
Make sure to download and extract the following libs into the `libs` folder:
- glfw 3.3.7: https://github.com/glfw/glfw/releases/tag/3.3.7
- glew 2.1.0: https://github.com/nigels-com/glew/releases/tag/glew-2.1.0
- glm 0.9.9.8: https://github.com/g-truc/glm/tree/0.9.9.8
- assimp 5.2.4: https://github.com/assimp/assimp/tree/v5.2.4
- bullet 3.24: https://github.com/bulletphysics/bullet3/tree/3.24

If new versions are available that you want to use, make sure to adjust the versions in the base `CMakeLists.txt`.
If you upgrade the `glfw` dependency, also adjust the version in the `main.cpp`.

## Usage
`Work in progress!`<br>
You can put `GLSL` shaders into the `res/shaders` directory. Then make sure to also add them into the `ShaderConsts` class for simple usage.<br>
