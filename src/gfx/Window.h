//
// Created by chloe on 16/06/2021.
//

#ifndef SATELLITESIM_WINDOW_H
#define SATELLITESIM_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window {
private:
    GLFWwindow* windowID;
public:
    Window(int width, int height);
    GLFWwindow* getWindowID();
    static void setupGLFW();
    static void setupGLAD();
};


#endif //SATELLITESIM_WINDOW_H
