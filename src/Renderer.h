#pragma once

#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

/**
 * Handles all OpenGL rendering done in the application.
 */
class Renderer
{
public:
    Renderer();

    // Init the Renderer, needs to be called before display
    void init(GLFWwindow* window);

    // Renders the shaders
    void display(GLFWwindow* window, double currentTime);

private:
    static const int numVAOs = 1;

    // Creates the OpenGL context and returns the program
    GLuint createShaderProgram();

    GLuint m_renderingProgram;
    GLuint m_vaos[numVAOs];

    // TODO: Remove
    float m_xOffset;
    float m_xInc;
};
