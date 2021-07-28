#include "gfx/Window.h"
#include "gfx/Shader.h"
#include "gfx/Model.h"
#include "util/Image.h"
#include "gfx/Camera2D.h"

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

//    GLuint simpleShader = Shader::loadShaders("simplevert.glsl", "simplefrag.glsl");
    Shader simpleShader("simplevert.glsl", "simplefrag.glsl");


    // Get a handle for our "MVP" uniform
    // Only during the initialisation
    GLuint MatrixID = simpleShader.getUniformLocation("MVP");


    Model model("assets/models/cube.obj");


    GLuint vbo, vao;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    model.bindBufferData();

    Image img("assets/textures/test3colour.bmp", IMGTYPE::BMP);
    Image img2("assets/textures/test3colour.bmp", IMGTYPE::BMP);
    img.loadImage();

    Camera2D camera(SCR_WIDTH, SCR_HEIGHT);

    double lastTime = glfwGetTime();

    while (!glfwWindowShouldClose(window.getWindowID()))
    {
        double currentTime = glfwGetTime();
        float deltaTime = float(currentTime - lastTime);
        lastTime = currentTime;

        if(glfwGetKey(window.getWindowID(), GLFW_KEY_SPACE)) {
            camera.zoomDifference(deltaTime * 10.f);
        }




        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        simpleShader.use();
        glm::mat4 modelMat = glm::mat4(1.f);
        camera.loadMVP(MatrixID, modelMat);

        glBindVertexArray(vao);
        model.drawModel();

        // Swap buffers
        glfwSwapBuffers(window.getWindowID());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}