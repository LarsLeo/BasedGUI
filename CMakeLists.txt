cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER $ENV{CXX_COMPILER})
set(CMAKE_C_COMPILER $ENV{C_COMPILER})
set (CMAKE_CXX_STANDARD 20)

set(PROJECT_NAME BasedGUI)
project(${PROJECT_NAME})

include(${CMAKE_BINARY_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup()

find_package(OpenGL REQUIRED)

# add the source code
file(GLOB_RECURSE SOURCES
    src/*.cpp
    src/*.h
    )

# add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Add libs
target_include_directories(${PROJECT_NAME} PRIVATE
    src
    .
)

set(ALL_LIBS
    ${OPENGL_LIBRARY}
    ${CONAN_LIBS}
)

# Compiler definitions
add_definitions(
    -DTW_STATIC
    -DTW_NO_LIB_PRAGMA
    -DTW_NO_DIRECT3D
    -DGLEW_STATIC
    -D_CRT_SECURE_NO_WARNINGS
)

# final linkage
target_link_libraries(${PROJECT_NAME}
    ${ALL_LIBS}
)
