//
// Created by chloe on 26/07/2021.
//

#include "Camera2D.h"

Camera2D::Camera2D(const unsigned int scr_width, const unsigned int scr_height) {
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

void Camera2D::updateCameraPos(Window window, float deltaTime) {
    if(glfwGetKey(window.getWindowID(), GLFW_KEY_W)) {
        this->view = glm::translate(view, glm::vec3(0.f, -1.f * deltaTime, 0.f));
    }
    if(glfwGetKey(window.getWindowID(), GLFW_KEY_A)) {
        this->view = glm::translate(view, glm::vec3(1.f * deltaTime, 0.f, 0.f));
    }
    if(glfwGetKey(window.getWindowID(), GLFW_KEY_S)) {
        this->view = glm::translate(view, glm::vec3(0.f, 1.f * deltaTime, 0.f));
    }
    if(glfwGetKey(window.getWindowID(), GLFW_KEY_D)) {
        this->view = glm::translate(view, glm::vec3(-1.f * deltaTime, 0.f, 0.f));
    }

}

void Camera2D::translateCamera() {
//    TODO

}
