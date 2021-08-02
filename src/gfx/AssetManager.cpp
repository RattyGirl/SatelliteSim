//
// Created by chloe on 2/08/2021.
//

#include "AssetManager.h"
void AssetManager::addModel(std::string name, Model model) {
//    does it contain
    bool found = false;
    for(int i = 0; i < models.size(); ++i) {
        if(models.at(i).first == name) {
            found = true;
            break;
        }
    }
    if(found)
        return;

    models.push_back(ModelPair(name, model));
}

void AssetManager::addShader(std::string name, Shader shader) {
//    does it contain
    bool found = false;
    for(int i = 0; i < shaders.size(); ++i) {
        if(shaders.at(i).first == name) {
            found = true;
            break;
        }
    }
    if(found)
        return;

    shaders.push_back(ShaderPair(name, shader));
}

Model *AssetManager::getModel(std::string name) {
    for (int i = 0; i < models.size(); ++i) {
        if(models.at(i).first == name) {
            return &models.at(i).second;
        }
    }
    return nullptr;
}

Shader *AssetManager::getShader(std::string name) {
    for (int i = 0; i < shaders.size(); ++i) {
        if(shaders.at(i).first == name) {
            return &shaders.at(i).second;
        }
    }
    return nullptr;
}
