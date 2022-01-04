#include "gfx/Window.h"
#include "gfx/Shader.h"
#include "gfx/Model.h"
#include "util/Image.h"
#include "gfx/Camera2D.h"
#include "gfx/AssetManager.h"
#include "game/SatelliteSim.h"

// settings
const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

AssetManager assetManager;

int main()
{
    Window::setupGLFW();
    Window window(SCR_WIDTH, SCR_HEIGHT);
    glfwMakeContextCurrent(window.getWindowID());
    Window::setupGLAD();

    Camera2D camera(SCR_WIDTH, SCR_HEIGHT, &window);
    SatelliteSim::SatelliteSim gameObject(&assetManager, &camera);

    gameObject.loadAssets();

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_MULTISAMPLE);

    GLuint vertexArrayID;
    glGenVertexArrays(1, &vertexArrayID);
    glBindVertexArray(vertexArrayID);

    GLuint vbo, vao;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);


    double lastTime = glfwGetTime();

    while (!glfwWindowShouldClose(window.getWindowID()))
    {
//        Delta Time Calc
        double currentTime = glfwGetTime();
        float deltaTime = (currentTime - lastTime);
        lastTime = currentTime;

        gameObject.update(deltaTime);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindVertexArray(vao);
        gameObject.render(&camera);

        // Swap buffers
        glfwSwapBuffers(window.getWindowID());
        glfwPollEvents();
    }

    assetManager.cleanImages();

    glfwTerminate();
    return 0;
}