#include "gfx/Window.h"
#include "gfx/Shader.h"
#include "gfx/Model.h"
#include "util/Image.h"
#include "gfx/Camera2D.h"
#include "gfx/AssetManager.h"

// settings
const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

int main()
{
    Window::setupGLFW();
    Window window(SCR_WIDTH, SCR_HEIGHT);
    glfwMakeContextCurrent(window.getWindowID());
    Window::setupGLAD();

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    GLuint vertexArrayID;
    glGenVertexArrays(1, &vertexArrayID);
    glBindVertexArray(vertexArrayID);

    AssetManager assetManager;
    assetManager.addShader("simpleshader", Shader("simplevert.glsl", "simplefrag.glsl"));
    GLuint MatrixID = assetManager.getShader("simpleshader")->getUniformLocation("MVP");

    assetManager.addModel("cube", Model("assets/models/cube.obj"));

    GLuint vbo, vao;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    assetManager.getModel("cube")->bindBufferData();

    Image img("assets/textures/emptygreen.bmp", IMGTYPE::BMP);
    img.loadImage();

    Camera2D camera(SCR_WIDTH, SCR_HEIGHT);

    double lastTime = glfwGetTime();

    while (!glfwWindowShouldClose(window.getWindowID()))
    {
        double currentTime = glfwGetTime();
        float deltaTime = float(currentTime - lastTime);
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
            std::cout << "Screen Pos:" << screenVec[0] << ":" << screenVec[1] << std::endl;
            std::cout << "World Pos:" << worldPos[0] << ":" << worldPos[1] << std::endl;
        }




        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        assetManager.getShader("simpleshader")->use();
        glBindVertexArray(vao);

        glm::mat4 transMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(1.f, 0.0f, 0.0f));
        glm::mat4 modelMat = transMatrix; //scales then rotates then translates
        camera.loadMVP(MatrixID, modelMat);
        assetManager.getModel("cube")->drawModel();

        transMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.f, 0.0f, 0.0f));
        modelMat = transMatrix; //scales then rotates then translates
        camera.loadMVP(MatrixID, modelMat);
        assetManager.getModel("cube")->drawModel();

        transMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.5f,0.245f, 0.0f));
        modelMat = transMatrix; //scales then rotates then translates
        camera.loadMVP(MatrixID, modelMat);
        assetManager.getModel("cube")->drawModel();

        // Swap buffers
        glfwSwapBuffers(window.getWindowID());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}