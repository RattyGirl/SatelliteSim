//
// Created by chloe on 26/07/2021.
//

#include "Camera2D.h"

Camera2D::Camera2D(unsigned int scr_width, unsigned int scr_height, Window* window) {
    this->m_window = window;
    this->m_scr_width = scr_width;
    this->m_scr_height = scr_height;
    m_position.x = 0.0f;
    m_position.y = 0.0f;

    m_view = glm::mat4(1.0);
    m_view[0][0] *= 200;
    m_view[1][1] *= 200;

    m_proj = glm::mat4(1.0);
    m_proj = glm::ortho(0.f, (float) scr_width, 0.f, (float) scr_height, 0.0f, 2.0f);
}

void Camera2D::loadMVP(GLuint matrixID, glm::mat4 model) {
    m_lastmvp = m_proj * m_view * model;
    glUniformMatrix4fv(matrixID, 1, GL_FALSE, &m_lastmvp[0][0]);
}

void Camera2D::zoomDifference(float z) {
    m_view[0][0] += z;
    m_view[1][1] += z;
}

float Camera2D::getRelativeXFromPixel(double xPos) {
    return 2.0f * xPos / this->m_scr_width - 1.0f;
}

float Camera2D::getRelativeYFromPixel(double yPos) {
    return -2.0f * yPos / this->m_scr_height + 1.0f;
}

glm::vec3 Camera2D::getWorldFromPixel(glm::vec3 screenPos) {
    glm::mat4 projectionInverse = glm::inverse(m_proj);
    glm::mat4 viewInverse = glm::inverse(m_view);
    return viewInverse * projectionInverse * glm::vec4(screenPos, 1.0f);
}

void Camera2D::updateCameraPos(float deltaTime) {

    int width, height;
    glfwGetFramebufferSize(m_window->getWindowID(), &width, &height);
    if(!(width == this->m_scr_width && height == this->m_scr_height)) {
        windowSizeCallback(m_window->getWindowID(), width, height);
    }

    if(glfwGetKey(m_window->getWindowID(), GLFW_KEY_SPACE)) {
        this->zoomDifference(deltaTime * 100.f);
    }
    if(glfwGetKey(m_window->getWindowID(), GLFW_KEY_W)) {
        this->translateCamera(0.f, -1.f * deltaTime);
    }
    if(glfwGetKey(m_window->getWindowID(), GLFW_KEY_A)) {
        this->translateCamera(1.f * deltaTime, 0.f);
    }
    if(glfwGetKey(m_window->getWindowID(), GLFW_KEY_S)) {
        this->translateCamera(0.f, 1.f * deltaTime);
    }
    if(glfwGetKey(m_window->getWindowID(), GLFW_KEY_D)) {
        this->translateCamera(-1.f * deltaTime, 0.f);
    }

    if(glfwGetMouseButton(m_window->getWindowID(), GLFW_MOUSE_BUTTON_RIGHT)) {
        double xpos, ypos;
        glfwGetCursorPos(m_window->getWindowID(), &xpos, &ypos);
        float xPosFloat = this->getRelativeXFromPixel(xpos);
        float yPosFloat = this->getRelativeYFromPixel(ypos);
        glm::vec3 screenVec = glm::vec3(xPosFloat, yPosFloat, 1);
        glm::vec3 worldPos = this->getWorldFromPixel(screenVec);
        if(!m_mouseHeld) {
            m_lastpos = worldPos;
            m_mouseHeld = true;
        } else {
            glm::vec2 diff = glm::vec2(worldPos.x, worldPos.y) - m_lastpos;
            this->translateCamera(diff.x, diff.y);
            m_mouseHeld = true;
        }
    } else {
        m_mouseHeld = false;
    }

//    if(glfwGetMouseButton(m_window->getWindowID(), GLFW_MOUSE_BUTTON_LEFT)) {
//        double xpos, ypos;
//        glfwGetCursorPos(m_window->getWindowID(), &xpos, &ypos);
//        float xPosFloat = this->getRelativeXFromPixel(xpos);
//        float yPosFloat = this->getRelativeYFromPixel(ypos);
//        glm::vec3 screenVec = glm::vec3(xPosFloat, yPosFloat, 1);
//        glm::vec3 worldPos = this->getWorldFromPixel(screenVec);
//        std::cout << this->m_position.x << this->m_position.y << ":" << worldPos.x << ", " << worldPos.y << std::endl;
//    }

}

void Camera2D::translateCamera(float dx, float dy) {
    this->m_view = glm::translate(m_view, glm::vec3(dx, dy, 0.f));
    m_position.x += dx;
    m_position.y += dy;
}

void Camera2D::windowSizeCallback(GLFWwindow* window, int width, int height) {
    this->m_scr_width = width;
    this->m_scr_height = height;

    m_proj = glm::mat4(1.0);
    m_proj = glm::ortho(0.f, (float) m_scr_width, 0.f, (float) m_scr_height, 0.0f, 2.0f);

    glViewport(0, 0, m_scr_width, m_scr_height);
}

const glm::vec2 &Camera2D::getPosition() const {
    return m_position;
}
