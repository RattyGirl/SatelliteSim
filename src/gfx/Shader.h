//
// Created by chloe on 3/07/2021.
//

#ifndef SATELLITESIM_SHADER_H
#define SATELLITESIM_SHADER_H


#include <glad/glad.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

class Shader {
private:
    GLuint programID;
    std::map<std::string, GLuint> knownUniformLocations;
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    GLuint getUniformLocation(std::string location);
    void use() const;

    static GLuint loadShaders(const char* vertex_file_path, const char* fragment_file_path);
};


#endif //SATELLITESIM_SHADER_H
