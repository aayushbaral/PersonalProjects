//
// Created by click on 4/5/2016.
//

#ifndef RAYTRACER_OPTIONS_H
#define RAYTRACER_OPTIONS_H

#include "Vector3D.h"
class Options{

    Options(){

    };
public:
    static Vector3D cameraPosition;
    static Vector3D cameraLookAt;
    static double cameraFOV;
};
#endif //RAYTRACER_OPTIONS_H
