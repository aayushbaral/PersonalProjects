//
<<<<<<< HEAD
// Created by click on 3/27/2016.
//

#include "ImageOutput.h"
#include <stdint.h>
#include "EasyBMP.h"
#include <iostream>
#include "Color.h"

void ImageOutput::draw(int height, int width, Color* color , const char* filename){


    BMP Image;
    Image.SetSize(width, height);
    Image.SetBitDepth(32);
    int loopCounter = 0;
    for (int i=0; i<width;i++){
        for (int j = 0; j<height; j++){
            loopCounter++;
            Color rgb = color[loopCounter];
            Image(i,j)->Red = rgb.getRedInt();
            Image(i, j)->Green = rgb.getGreenInt();
            Image(i, j) ->Blue = rgb.getBlueInt();
            Image(i, j) ->Alpha = rgb.getAlphaInt();
        }
        //Plane



=======
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
>>>>>>> 032e94aa29a84150216fda26b3822892ce649ed6

    }
    Image.WriteToFile(filename);


}
<<<<<<< HEAD
=======

>>>>>>> 032e94aa29a84150216fda26b3822892ce649ed6
