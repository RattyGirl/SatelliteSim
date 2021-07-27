//
// Created by chloe on 26/07/2021.
//

#include "Camera2D.h"

Camera2D::Camera2D(const unsigned int scr_width, const unsigned int scr_height) {
    this->scr_width = scr_width;
    this->scr_height = scr_height;
    position.x = 0.0f;
    position.y = 0.0f;
}
