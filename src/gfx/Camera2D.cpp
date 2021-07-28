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
    view[0][0] *= 400;
    view[1][1] *= 400;


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
