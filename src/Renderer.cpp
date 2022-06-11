#include "Renderer.h"

#include <string>
#include <iostream>

#include "FileUtils.h"
#include "ShaderConsts.h"
#include "LogUtils.h"

Renderer::Renderer()
    : m_renderingProgram(-1)
    , m_xOffset(0.0f)
    , m_xInc(0.01f)
{
}

void Renderer::init(GLFWwindow* window)
{
    m_renderingProgram = createShaderProgram();

    glGenVertexArrays(numVAOs, m_vaos);
    glBindVertexArray(m_vaos[0]);
    glUseProgram(m_renderingProgram);
}

void Renderer::display(GLFWwindow* window, double currentTime)
{
    glClear( GL_DEPTH_BUFFER_BIT );
    glClear( GL_COLOR_BUFFER_BIT );

    m_xOffset += m_xInc;
    if (m_xOffset > 1 || m_xOffset < 0)
    {
        m_xInc = -m_xInc;
    }
    GLuint offsetLoc = glGetUniformLocation(m_renderingProgram, "offset");
    glProgramUniform1f(m_renderingProgram, offsetLoc, m_xOffset);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}

GLuint Renderer::createShaderProgram()
{
    const std::string baseVertexContent = FileUtils::readFile(ShaderConsts::BASE_VERTEX_SRC);
    const std::string baseFragmentContent = FileUtils::readFile(ShaderConsts::BASE_FRAGMENT_SRC);
    const char* vShaderSource = baseVertexContent.c_str();
    const char* fShaderSource = baseFragmentContent.c_str();

    GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(vShader, 1, &vShaderSource, nullptr);
    glShaderSource(fShader, 1, &fShaderSource, nullptr);

    GLint vertCompiled;
    glCompileShader(vShader);
    LogUtils::checkOpenGLError();
    glGetShaderiv(vShader, GL_COMPILE_STATUS, &vertCompiled);
    if (vertCompiled != 1)
    {
        std::cout << "Vertex compilation failed!";
        LogUtils::printShaderLog(vShader);
    }

    GLint fragCompiled;
    glCompileShader(fShader);
    LogUtils::checkOpenGLError();
    glGetShaderiv(fShader, GL_COMPILE_STATUS, &fragCompiled);
    if (fragCompiled != 1)
    {
        std::cout << "Fragment compilation failed!";
        LogUtils::printShaderLog(fShader);
    }

    GLuint program = glCreateProgram();
    glAttachShader(program, vShader);
    glAttachShader(program, fShader);

    GLint linked;
    glLinkProgram(program);
    LogUtils::checkOpenGLError();
    if (linked != 1)
    {
        std::cout << "Linking failed!";
        LogUtils::printProgramLog(m_renderingProgram);
    }

    return program;
}
