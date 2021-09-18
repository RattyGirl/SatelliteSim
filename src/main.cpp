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

    SatelliteSim::SatelliteSim gameObject(&assetManager);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_MULTISAMPLE);

    GLuint vertexArrayID;
    glGenVertexArrays(1, &vertexArrayID);
    glBindVertexArray(vertexArrayID);


    assetManager.addShader("simpleshader", Shader("simplevert.glsl", "simplefrag.glsl"));
    assetManager.addModel("cube", Model("assets/models/cube.obj"));

    GLuint vbo, vao;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    assetManager.getModel("cube")->bindBufferData();

    Camera2D camera(SCR_WIDTH, SCR_HEIGHT);

    assetManager.addImage("emptygreen", Image("assets/textures/emptygreen.bmp", IMGTYPE::BMP));
    assetManager.getImage("emptygreen")->loadImage();

    double lastTime = glfwGetTime();

    while (!glfwWindowShouldClose(window.getWindowID()))
    {
        double currentTime = glfwGetTime();
        float deltaTime = (currentTime - lastTime);
        lastTime = currentTime;

        if(glfwGetKey(window.getWindowID(), GLFW_KEY_SPACE)) {
            camera.zoomDifference(deltaTime * 100.f);
        }
        camera.updateCameraPos(window, deltaTime);

        if(glfwGetMouseButton(window.getWindowID(), GLFW_MOUSE_BUTTON_LEFT)) {
            double xpos, ypos;
            glfwGetCursorPos(window.getWindowID(), &xpos, &ypos);
            float xPosFloat = camera.getRelativeXFromPixel(xpos);
            float yPosFloat = camera.getRelativeYFromPixel(ypos);
            glm::vec3 screenVec = glm::vec3(xPosFloat, yPosFloat, 1);
            glm::vec3 worldPos = camera.getWorldFromPixel(screenVec);
        }


        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        assetManager.getShader("simpleshader")->use();
        glBindVertexArray(vao);
        gameObject.render(&camera);

        // Swap buffers
        glfwSwapBuffers(window.getWindowID());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}