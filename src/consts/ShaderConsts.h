#pragma once

#include <string>

class ShaderConsts
{
public:
    enum class ShaderType
    {
        Vertex,
        Fragment
    };

    // Vertex shaders
    static const std::string BASE_VERTEX_SRC;
    static const std::string BASE_VERTEX_ROTATION;
    static const std::string BASE_VERTEX_TRANSLATION;
    static const std::string BASE_VERTEX_SCALE;

    // Fragment shaders
    static const std::string BASE_FRAGMENT_SRC;
};
