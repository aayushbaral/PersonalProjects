
// Created by click on 2/28/2016.
//

#ifndef IMAGEOUTPUT_IMAGEOUTPUT_H
#define IMAGEOUTPUT_IMAGEOUTPUT_H
#include "EasyBMP/EasyBMP.h"
#include "Color.h"


class ImageOutput {

    public:
        ImageOutput(){};
        //Using draw function from the Easy BMP library
        static void draw(int height, int width, Color* color,const char* filename);
        //static void Color(char* red, char* blue, char* green);







};

#endif
