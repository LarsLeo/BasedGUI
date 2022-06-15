#pragma once

#include <GL/glew.h>

class LogUtils
{
public:
    static void printShaderLog(GLuint shader);
    static void printProgramLog(int program);
    static bool checkOpenGLError();
};
