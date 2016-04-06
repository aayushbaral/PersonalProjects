//
// Created by click on 3/27/2016.
//

#ifndef RAYTRACER_SHAPE_H
#define RAYTRACER_SHAPE_H

#include "Ray.h"
#include "Color.h"


class Shape {
protected:
    float ambience;
public:
    virtual const Color getColor() = 0;
    virtual const double getIntersectionDistance(Ray r) = 0;
    Shape(float a){
        ambience = a;
    }
    virtual const Vector3D getNormalFor(Vector3D intersectionPoint) = 0;
    float getAmbience(){
        return ambience;
    }

};


#endif //RAYTRACER_SHAPE_H
