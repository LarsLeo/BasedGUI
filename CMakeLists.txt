cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++")
set(CMAKE_C_COMPILER "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang")

set (CMAKE_CXX_STANDARD 20)

# set the project name
project(BasedGUI)

find_package(OpenGL REQUIRED)

# Compile external libs
add_subdirectory (libs)

include_directories(
    libs/glfw-3.1.2/include/
    libs/glm-0.9.7.1/
    libs/glew-1.13.0/include/
    libs/assimp-3.0.1270/include/
    libs/bullet-2.81-rev2613/src/
    .
)

set(ALL_LIBS
    ${OPENGL_LIBRARY}
    glfw
    GLEW_1130
)

add_definitions(
    -DTW_STATIC
    -DTW_NO_LIB_PRAGMA
    -DTW_NO_DIRECT3D
    -DGLEW_STATIC
    -D_CRT_SECURE_NO_WARNINGS
)

# add the source code
file(GLOB_RECURSE SOURCES
    src/*.cpp
    src/*.h
    )

# add the executable
add_executable(BasedGUI ${SOURCES})

# final linkage
target_link_libraries(BasedGUI
    ${ALL_LIBS}
)
