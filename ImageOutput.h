//
// Created by click on 3/27/2016.
//

#ifndef RAYTRACER_IMAGEOUTPUT_H
#define RAYTRACER_IMAGEOUTPUT_H

#include "Color.h"


class ImageOutput {
public:
    ImageOutput(){};
    static void draw(int height, int width, Color* color, const char* filename);


};


#endif //RAYTRACER_IMAGEOUTPUT_H
