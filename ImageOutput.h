//
<<<<<<< HEAD
// Created by click on 3/27/2016.
//

#ifndef RAYTRACER_IMAGEOUTPUT_H
#define RAYTRACER_IMAGEOUTPUT_H

#include "Color.h"


class ImageOutput {
public:
    ImageOutput(){};
    static void draw(int height, int width, Color* color, const char* filename);
=======
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







>>>>>>> 032e94aa29a84150216fda26b3822892ce649ed6


};


<<<<<<< HEAD
#endif //RAYTRACER_IMAGEOUTPUT_H
=======
#endif //IMAGEOUTPUT_IMAGEOUTPUT_H
>>>>>>> 032e94aa29a84150216fda26b3822892ce649ed6
