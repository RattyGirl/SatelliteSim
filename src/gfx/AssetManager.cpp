//
// Created by chloe on 2/08/2021.
//

#include "AssetManager.h"
void AssetManager::addModel(const std::string& name, const Model& model) {
//    does it contain
    bool found = false;
    for(auto &loopModel : models) {
        if(loopModel.first == name) {
            found = true;
            break;
        }
    }
    if(found)
        return;

    models.emplace_back(name, model);
}

void AssetManager::addShader(const std::string& name, Shader shader) {
//    does it contain
    bool found = false;
    for(auto &loopShader : shaders) {
        if(loopShader.first == name) {
            found = true;
            break;
        }
    }
    if(found)
        return;

    shaders.emplace_back(name, shader);
}

void AssetManager::addImage(const std::string& name, Image image) {
//    does it contain
    bool found = false;
    for(auto &loopImage : images) {
        if(loopImage.first == name) {
            found = true;
            break;
        }
    }
    if(found)
        return;

    images.emplace_back(name, image);
}

Model *AssetManager::getModel(const std::string& name) {
    for (auto &model : models) {
        if(model.first == name) {
            return &model.second;
        }
    }
    return nullptr;
}

Shader *AssetManager::getShader(const std::string& name) {
    for (auto &shader : shaders) {
        if(shader.first == name) {
            return &shader.second;
        }
    }
    return nullptr;
}

Image *AssetManager::getImage(const std::string& name) {
    for (auto &image : images) {
        if(image.first == name) {
            return &image.second;
        }
    }
    return nullptr;
}