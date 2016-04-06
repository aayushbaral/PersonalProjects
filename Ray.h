//
// Created by click on 3/27/2016.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H
#include "Vector3D.h"


class Ray {
private:
    Vector3D direction;
    Vector3D origin;
public:
    Ray(const Vector3D _o, const Vector3D _d);
    Ray(){};
//Getters for this class
    Vector3D getOrigin(){
        return origin;
    }
    Vector3D getDirection(){
        return  direction;
    }

};


#endif //RAYTRACER_RAY_H
