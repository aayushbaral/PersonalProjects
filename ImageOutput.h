//
// Created by click on 2/28/2016.
//

#ifndef IMAGEOUTPUT_IMAGEOUTPUT_H
#define IMAGEOUTPUT_IMAGEOUTPUT_H
#include "EasyBMP/EasyBMP.h"



class ImageOutput {

    public:
        ImageOutput(){};
        ~ImageOutput();
        void draw(int height, int width, uint8_t colors[],const char* filename);
        //static void Color(char* red, char* blue, char* green);









};


#endif //IMAGEOUTPUT_IMAGEOUTPUT_H
