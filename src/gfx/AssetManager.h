//
// Created by chloe on 2/08/2021.
//

#ifndef SATELLITESIM_ASSETMANAGER_H
#define SATELLITESIM_ASSETMANAGER_H


#include <string>
#include "Model.h"
#include "Shader.h"
#include "../util/Image.h"

typedef std::pair<std::string, Model> ModelPair;
typedef std::pair<std::string, Shader> ShaderPair;
typedef std::pair<std::string, Image> ImagePair;

class AssetManager {
private:
    std::vector<ModelPair> models;
    std::vector<ShaderPair> shaders;
    std::vector<ImagePair> images;
public:
    void addModel(std::string name, Model model);
    void addShader(std::string name, Shader shader);
    void addImage(std::string name, Image shader);

    Model* getModel(std::string name);
    Shader* getShader(std::string name);
    Image* getImage(std::string name);
};


#endif //SATELLITESIM_ASSETMANAGER_H
