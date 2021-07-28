//
// Created by chloe on 26/07/2021.
//

#ifndef SATELLITESIM_CAMERA2D_H
#define SATELLITESIM_CAMERA2D_H


#include <glm/vec2.hpp>
#include "Model.h"
#include "Shader.h"

class Camera2D {
private:
    glm::vec2 position;
    int scr_width, scr_height;
    float zoom = 2000;
    glm::mat4 view;
    glm::mat4 proj;

    glm::mat4 lastmvp;
public:
    Camera2D(unsigned int scr_width, unsigned int scr_height);

    void loadMVP(GLuint matrixID, glm::mat4 model);
    void zoomDifference(float z);
    void translateCamera();
};


#endif //SATELLITESIM_CAMERA2D_H
