//
// Created by chloe on 26/07/2021.
//

#ifndef SATELLITESIM_CAMERA2D_H
#define SATELLITESIM_CAMERA2D_H


#include <glm/vec2.hpp>

class Camera2D {
private:
    glm::vec2 position;
    int scr_width, scr_height;
public:
    Camera2D(const unsigned int scr_width, const unsigned int scr_height);

};


#endif //SATELLITESIM_CAMERA2D_H
