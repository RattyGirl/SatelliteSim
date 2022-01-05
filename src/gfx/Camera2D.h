//
// Created by chloe on 26/07/2021.
//

#ifndef SATELLITESIM_CAMERA2D_H
#define SATELLITESIM_CAMERA2D_H


#include <glm/vec2.hpp>
#include "Model.h"
#include "Shader.h"
#include "Window.h"

class Camera2D {
private:
    glm::vec2 m_position;
    int m_scr_width, m_scr_height;
    float m_zoom = 2000;
    glm::mat4 m_view;
    glm::mat4 m_proj;

    glm::mat4 m_lastmvp;

    bool m_mouseHeld = false;
    glm::vec2 m_lastpos;

    Window* m_window;
public:
    Camera2D(unsigned int scr_width, unsigned int scr_height, Window *pWindow);

    void loadMVP(GLuint matrixID, glm::mat4 model);
    void zoomDifference(float z);
    void translateCamera(float dx, float dy);
    float getRelativeXFromPixel(double xPos);
    float getRelativeYFromPixel(double yPos);
    glm::vec3 getWorldFromPixel(glm::vec3 screenPos);

    void updateCameraPos(float deltaTime);
    void windowSizeCallback(GLFWwindow* window, int width, int height);
    const glm::vec2 &getPosition() const;
};


#endif //SATELLITESIM_CAMERA2D_H
