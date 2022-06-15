#pragma once

#include <string>

class ShaderConsts
{
public:
    static enum class ShaderType
    {
        Vertex,
        Fragment
    };

    static const std::string BASE_VERTEX_SRC;
    static const std::string BASE_FRAGMENT_SRC;
};
