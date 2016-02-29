//
// Created by click on 2/28/2016.
//

#include "ImageOutput.h"
#include <iostream>
#include <stdint.h>
#include "EasyBMP/EasyBMP.h"



void ImageOutput::draw(int height, int width, uint8_t colors[], const char* filename){

    BMP Image;
    Image.SetSize(height, width);
    Image.SetBitDepth(32);
    for (int i=0; i<width;i++){
        for (int j = 0; j<height; j++){
            Image (i, j)-> Red =colors[0];
            Image (i, j) -> Green =colors[1];
            Image (i, j) -> Blue = colors[2];
            Image (i, j) -> Alpha = colors [3];
        }

    }
    Image.WriteToFile(filename);


}

