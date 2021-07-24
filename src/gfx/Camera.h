//
// Created by chloe on 5/07/2021.
//

#ifndef SATELLITESIM_CAMERA_H
#define SATELLITESIM_CAMERA_H

#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>


class Camera {
private:
    int scr_width, scr_height;
    glm::mat4 projection;
    glm::mat4 view;
    glm::mat4 mvp;

    glm::vec3 position = glm::vec3( 0, 0, 5 );
    // horizontal angle : toward -Z
    float horizontalAngle = 3.14f;
    // vertical angle : 0, look at the horizon
    float verticalAngle = 0.0f;
    float currentFOV = 45.0f;
    float speed = 3.0f; // 3 units / second
    float mouseSpeed = 0.005f;
public:
    Camera(int scr_width, int scr_height);
    void loadMVP(GLuint uniformID, glm::mat4 modelMatrix);
    void updateFOV(float newFOV);
    void updateViewMatrix();
    void translateCamera(glm::vec3 translation);
    void rotateCamera(float horizontalRotation, float verticalRotation);
};


#endif //SATELLITESIM_CAMERA_H
