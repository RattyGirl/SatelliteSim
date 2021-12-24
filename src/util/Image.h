//
// Created by chloe on 18/07/2021.
//

#ifndef SATELLITESIM_IMAGE_H
#define SATELLITESIM_IMAGE_H

#include <glad/glad.h>
#include <iostream>

enum IMGTYPE {BMP, PNG};
class Image {
private:
    int width,height;
    GLuint textureID;
    IMGTYPE imgtype;

    // Actual RGB data
    unsigned char* data;

    void parseBMP(const char *path);
public:
    Image(const char* path, IMGTYPE filetype);
    void cleanup();

    void loadImage();
    static GLuint loadBMP(const char* path);
};


#endif //SATELLITESIM_IMAGE_H
