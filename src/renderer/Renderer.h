#pragma once

#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "consts/ShaderConsts.h"

/**
 * Handles all OpenGL rendering done in the application.
 */
class Renderer
{
public:
    Renderer();

    // Init the Renderer, needs to be called before anything else.
    // Also creates the glfw window and returns a pointer to it
    GLFWwindow* init(std::string title, int windowWidth, int windowHeight);

    // Renders the shaders
    void display(GLFWwindow* window, double currentTime);

    // Adds a given shader of the type to the currently running program
    bool addShader(ShaderConsts::ShaderType type, std::string fileName);

    // Relinks the current program.
    // Call after addding all your shaders
    bool linkProgram();

    // TODO: remove
    // Creates the OpenGL context and returns the program
    GLuint createShaderProgram();

private:
    static const int numVAOs = 1;

    GLuint m_renderingProgram;
    GLuint m_vaos[numVAOs];

    // TODO: Remove
//    float m_xOffset;
//    float m_xInc;
};
