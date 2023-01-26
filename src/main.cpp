#include <stdlib.h>
#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "renderer/Renderer.h"
#include "consts/ShaderConsts.h"

int main( void )
{
    std::unique_ptr<Renderer> renderer = std::make_unique<Renderer>();
    auto window = renderer->init("BasedGUI", 1024, 768);

    if (!window)
    {
        return 1;
    }

    renderer->createShaderProgram();
    // TODO: Make shader pipeline work dynamically
//    renderer->addShader(ShaderConsts::ShaderType::Vertex, ShaderConsts::BASE_VERTEX_SRC);
//    renderer->addShader(ShaderConsts::ShaderType::Fragment, ShaderConsts::BASE_FRAGMENT_SRC);
//    renderer->linkProgram();

    do{
        renderer->display(window, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}
