//
// Created by chloe on 18/07/2021.
//

#ifndef SATELLITESIM_MODEL_H
#define SATELLITESIM_MODEL_H


#include <vector>
#include <glm/gtc/matrix_transform.hpp>

class Model {
private:
    std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
    std::vector< glm::vec3 > temp_vertices;
    std::vector< glm::vec2 > temp_uvs;
    std::vector< glm::vec3 > temp_normals;


    std::vector< glm::vec3 > vertices;
    std::vector< glm::vec2 > uvs;
    std::vector< glm::vec3 > normals; // Won't be used at the moment.

    std::vector<float> combined;
public:
    Model(const char* location);

    void bindBufferData();

    void drawModel();
};


#endif //SATELLITESIM_MODEL_H
