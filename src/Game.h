#ifndef SATELLITESIMULATOR_GAME_H
#define SATELLITESIMULATOR_GAME_H
#include <glad/gl.h>
#include <GLFW/glfw3.h>

class Game {
private:
    GLFWwindow* window;

public:
    Game();
    void run();
};

#endif //SATELLITESIMULATOR_GAME_H
