//
// Created by chloe on 26/07/2021.
//

#include "Camera2D.h"

Camera2D::Camera2D(unsigned int scr_width, unsigned int scr_height, Window* window) {
    this->window = window;
    this->scr_width = scr_width;
    this->scr_height = scr_height;
    position.x = 0.0f;
    position.y = 0.0f;

    view = glm::mat4(1.0);
    view[0][0] *= 200;
    view[1][1] *= 200;

    proj = glm::mat4(1.0);
    proj = glm::ortho(0.f, (float) scr_width, 0.f, (float) scr_height, 0.0f, 2.0f);
}

void Camera2D::loadMVP(GLuint matrixID, glm::mat4 model) {
    lastmvp = proj * view * model;
    glUniformMatrix4fv(matrixID, 1, GL_FALSE, &lastmvp[0][0]);
}

void Camera2D::zoomDifference(float z) {
    view[0][0] += z;
    view[1][1] += z;
}

float Camera2D::getRelativeXFromPixel(double xPos) {
    return 2.0f * xPos / this->scr_width - 1.0f;
}

float Camera2D::getRelativeYFromPixel(double yPos) {
    return -2.0f * yPos / this->scr_height + 1.0f;
}

glm::vec3 Camera2D::getWorldFromPixel(glm::vec3 screenPos) {
    glm::mat4 projectionInverse = glm::inverse(proj);
    glm::mat4 viewInverse = glm::inverse(view);
    return viewInverse * projectionInverse * glm::vec4(screenPos, 1.0f);
}

void Camera2D::updateCameraPos(float deltaTime) {

    int width, height;
    glfwGetFramebufferSize(window->getWindowID(), &width, &height);
    if(!(width == this->scr_width && height == this->scr_height)) {
        windowSizeCallback(window->getWindowID(), width, height);
    }

    if(glfwGetKey(window->getWindowID(), GLFW_KEY_SPACE)) {
        this->zoomDifference(deltaTime * 100.f);
    }
    if(glfwGetKey(window->getWindowID(), GLFW_KEY_W)) {
        this->view = glm::translate(view, glm::vec3(0.f, -1.f * deltaTime, 0.f));
    }
    if(glfwGetKey(window->getWindowID(), GLFW_KEY_A)) {
        this->view = glm::translate(view, glm::vec3(1.f * deltaTime, 0.f, 0.f));
    }
    if(glfwGetKey(window->getWindowID(), GLFW_KEY_S)) {
        this->view = glm::translate(view, glm::vec3(0.f, 1.f * deltaTime, 0.f));
    }
    if(glfwGetKey(window->getWindowID(), GLFW_KEY_D)) {
        this->view = glm::translate(view, glm::vec3(-1.f * deltaTime, 0.f, 0.f));
    }

    if(glfwGetMouseButton(window->getWindowID(), GLFW_MOUSE_BUTTON_LEFT)) {
        double xpos, ypos;
        glfwGetCursorPos(window->getWindowID(), &xpos, &ypos);
        float xPosFloat = this->getRelativeXFromPixel(xpos);
        float yPosFloat = this->getRelativeYFromPixel(ypos);
        glm::vec3 screenVec = glm::vec3(xPosFloat, yPosFloat, 1);
        glm::vec3 worldPos = this->getWorldFromPixel(screenVec);
    }

}

void Camera2D::translateCamera() {
//    TODO
}

void Camera2D::windowSizeCallback(GLFWwindow* window, int width, int height) {
    this->scr_width = width;
    this->scr_height = height;

    proj = glm::mat4(1.0);
    proj = glm::ortho(0.f, (float) scr_width, 0.f, (float) scr_height, 0.0f, 2.0f);

    glViewport(0, 0, scr_width, scr_height);
}