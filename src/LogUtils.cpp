#include "LogUtils.h"

#include <iostream>

void LogUtils::printShaderLog(GLuint shader)
{
    int len = 0;
    int charsWritten = 0;
    char* log;

    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);

    if (len > 0)
    {
        log = (char*)malloc(len);
        glGetShaderInfoLog(shader, len, &charsWritten, log);
        std::cout << "Shader Info Log: " << log << std::endl;
        free(log);
    }
}

void LogUtils::printProgramLog(int program)
{
    int len = 0;
    int charsWritten = 0;
    char* log;

    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);

    if (len > 0)
    {
        log = (char*)malloc(len);
        glGetProgramInfoLog(program, len, &charsWritten, log);
        std::cout << "Program Info Log: " << log << std::endl;
        free(log);
    }
}

bool LogUtils::checkOpenGLError()
{
    bool foundError = false;
    int glErr = glGetError();

    while (glErr != GL_NO_ERROR)
    {
        std::cout << "glError: " << glErr << std::endl;
        foundError = true;
        glErr = glGetError();
    }

    return foundError;
}
