//
// Created by chloe on 16/06/2021.
//

#include "SatelliteSim.h"

namespace SatelliteSim {
    void SatelliteSim::render(Camera2D* camera) {
        GLuint MatrixID = assetManager->getShader("simpleshader")->getUniformLocation("MVP");
//        draw world
        for (int y = 0; y < 10; ++y) {
            for (int x = 0; x < 10; ++x) {
                float yCoord = 0.245f * (float)y;
                float xCoord;
                if(y % 2) {
                    xCoord = 0.5f + 1.f * (float)x;
                } else {
                    xCoord = 1.f * (float)x;
                }
                glm::mat4 modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(xCoord, yCoord, 0.0f));
                glm::mat4 modelMat = modelMatrix; //scales then rotates then translates
                camera->loadMVP(MatrixID, modelMat);
                assetManager->getModel("cube")->drawModel();
            }
        }
    }


    void SatelliteSim::loadAssets() {
        assetManager->addModel("cube", Model("assets/models/cube.obj"));

        assetManager->addShader("simpleshader", Shader("simplevert.glsl", "simplefrag.glsl"));

        assetManager->addImage("emptygreen", Image("assets/textures/emptygreen.bmp", IMGTYPE::BMP));

    }

    void SatelliteSim::update(float dt) {
        camera->updateCameraPos(dt);
    }
}