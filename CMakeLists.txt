cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER $ENV{CXX_COMPILER})
set(CMAKE_C_COMPILER $ENV{C_COMPILER})
set (CMAKE_CXX_STANDARD 20)

set(GLFW_LIB glfw-3.3.7)
set(GLEW_LIB glew-2.1.0)
set(ASSIMP_LIB assimp-5.2.4)
set(GLM_LIB glm-0.9.9.8)
set(BULLET_LIB bullet3-3.24)
set(BULLET_VERSION 3.24) # needs to be set for bullets CMakeLists to work

# set the project name
project(BasedGUI)

find_package(OpenGL REQUIRED)

# Compile external libs
add_subdirectory (libs)

include_directories(
    libs/${GLFW_LIB}/include/
    libs/${GLM_LIB}/
    libs/${GLEW_LIB}/include/
    libs/${ASSIMP_LIB}/include/
    libs/${BULLET_LIB}/src/
    .
)

set(ALL_LIBS
    ${OPENGL_LIBRARY}
    glfw
    GLEW_210
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
