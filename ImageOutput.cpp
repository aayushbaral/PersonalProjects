//

// Created by click on 3/27/2016.
//

#include"ImageOutput.h"
#include <stdint.h>
#include "EasyBMP/EasyBMP.h"
#include <iostream>
#include "Color.h"

void ImageOutput::draw(int height, int width, Color* color , const char* filename) {


    BMP Image;
    Image.SetSize(width, height);



    Image.SetBitDepth(32);
    int loopCounter = 0;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            loopCounter++;
            Color rgb = color[loopCounter];
            Image(i, j)->Red = rgb.getRedInt();
            Image(i, j)->Green = rgb.getGreenInt();
            Image(i, j)->Blue = rgb.getBlueInt();
            Image(i, j)->Alpha = rgb.getAlphaInt();
        }
    }
    Image.WriteToFile(filename);


}
        //Plane



