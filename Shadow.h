//
// Created by click on 4/5/2016.
//

#ifndef RAYTRACER_SHADOW_H
#define RAYTRACER_SHADOW_H


#include "Vector3D.h"

class Shadow {

private:

    Vector3D originOfShadow;
    Vector3D directionOfShadow;
private:
    Shadow(){};
    Shadow(Vector3D _origin, Vector3D _direction){
        originOfShadow = _origin;
        directionOfShadow = _direction;

    }

};


#endif //RAYTRACER_SHADOW_H
