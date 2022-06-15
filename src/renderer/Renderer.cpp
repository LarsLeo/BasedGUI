#include "Renderer.h"

#include <string>
#include <iostream>

#include "utils/FileUtils.h"
#include "utils/LogUtils.h"

Renderer::Renderer()
    : m_renderingProgram(-1)
//    , m_xOffset(0.0f)
//    , m_xInc(0.01f)
{
}

GLFWwindow* Renderer::init(std::string title, int windowWidth, int windowHeight)
{
    // Initialise GLFW
    if(!glfwInit())
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        return nullptr;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    auto window = glfwCreateWindow(windowWidth, windowHeight, title.c_str(), nullptr, nullptr);
    if(!window) {
        fprintf( stderr, "Failed to open GLFW window!\n" );
        glfwTerminate();
        return nullptr;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        glfwTerminate();
        return nullptr;
    }

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glfwSwapInterval(1);
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);


    m_renderingProgram = createShaderProgram();

    glGenVertexArrays(numVAOs, m_vaos);
    glBindVertexArray(m_vaos[0]);
    glUseProgram(m_renderingProgram);

    return window;
}

void Renderer::display(GLFWwindow* window, double currentTime)
{
    glClear( GL_DEPTH_BUFFER_BIT );
    glClear( GL_COLOR_BUFFER_BIT );

//    m_xOffset += m_xInc;
//    if (m_xOffset > 1 || m_xOffset < 0)
//    {
//        m_xInc = -m_xInc;
//    }
//    GLuint offsetLoc = glGetUniformLocation(m_renderingProgram, "offset");
//    glProgramUniform1f(m_renderingProgram, offsetLoc, m_xOffset);

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

bool Renderer::addShader(ShaderConsts::ShaderType type, std::string fileName)
{
    if (m_renderingProgram == -1)
    {
        // Renderer has not been initialized yet
        return false;
    }

    const std::string shaderContent = FileUtils::readFile(fileName);
    const char* shaderSource = shaderContent.c_str();

    GLuint shader;
    if (type == ShaderConsts::ShaderType::Fragment)
    {
        shader = glCreateShader(GL_FRAGMENT_SHADER);
    }
    else
    {
        shader = glCreateShader(GL_VERTEX_SHADER);
    }

    glShaderSource(shader, 1, &shaderSource, nullptr);

    GLint compiled;
    glCompileShader(shader);
    LogUtils::checkOpenGLError();
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if (compiled != 1)
    {
        std::cout << "Vertex compilation failed!";
        LogUtils::printShaderLog(shader);
    }

    glAttachShader(m_renderingProgram, shader);

    return true;
}

bool Renderer::linkProgram()
{
    if (m_renderingProgram == -1)
    {
        // Renderer has not been initialized yet
        return false;
    }

    GLint linked;
    glLinkProgram(m_renderingProgram);
    LogUtils::checkOpenGLError();
    if (linked != 1)
    {
        std::cout << "Linking failed!";
        LogUtils::printProgramLog(m_renderingProgram);
    }

    return true;
}
