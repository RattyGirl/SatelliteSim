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
    void addModel(const std::string& name, const Model& model);
    void addShader(const std::string& name, Shader shader);
    void addImage(const std::string& name, Image shader);

    Model* getModel(const std::string& name);
    Shader* getShader(const std::string& name);
    Image* getImage(const std::string& name);

    void cleanImages();
};


#endif //SATELLITESIM_ASSETMANAGER_H
