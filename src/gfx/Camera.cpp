//
// Created by chloe on 5/07/2021.
//

#include "Camera.h"

Camera::Camera(int scr_width, int scr_height) {
    this->scr_width = scr_width;
    this->scr_height = scr_height;
    this->updateFOV(this->currentFOV);
    this->updateViewMatrix();
}

void Camera::updateFOV(float newFOV) {
    this->currentFOV = newFOV;
    // Projection matrix : Field of View, screen ratio, display range : 0.1 unit <-> 100 units
    this->projection = glm::perspective(glm::radians(this->currentFOV), (float) scr_width / (float)scr_height, 0.1f, 100.0f);
    // Or, for an ortho camera :
//    this->projection = glm::ortho(-halfWidth,halfWidth,-halfHeight,halfHeight,-100.0f,100.0f); // In world coordinates
}

void Camera::translateCamera(glm::vec3 translation) {
    this->position += translation;
    updateViewMatrix();
}

void Camera::updateViewMatrix() {
    glm::vec3 direction(
            cos(verticalAngle) * sin(horizontalAngle),
            sin(verticalAngle),
            cos(verticalAngle) * cos(horizontalAngle)
    );

    // Camera matrix
    this->view = glm::lookAt(
            position, // Camera is at (4,3,3), in World Space
            position + direction, // and looks at the origin
            glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
    );
}

void Camera::loadMVP(GLuint uniformID, glm::mat4 modelMatrix) {
    mvp = projection * view * modelMatrix; // Remember, matrix multiplication is the other way around
    glUniformMatrix4fv(uniformID, 1, GL_FALSE, &mvp[0][0]);
}

void Camera::rotateCamera(float horizontalRotation, float verticalRotation) {
    this->horizontalAngle += horizontalRotation;
    this->verticalAngle += verticalRotation;
    this->updateViewMatrix();
}
