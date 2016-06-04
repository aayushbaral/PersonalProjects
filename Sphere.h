//
// Created by click on 3/27/2016.
//
#pragma once
#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "Shape.h"


class Sphere: public Shape {
private:
    Color colorOfSphere;
    Vector3D centerOfSphere;
    double radius;

public:
    Sphere():Shape(){};
    Sphere(float _ambience, float _diffusedCoefficient, float _specularCoefficient, Vector3D _center,

           Color _sphereColor, double _r):Shape(_ambience, _diffusedCoefficient, _specularCoefficient){
        centerOfSphere = _center;
        colorOfSphere = _sphereColor;
        radius = _r;

    }
    const Color getColor();
    const Vector3D getNormalFor(Vector3D intersectionPoint);
    const double getIntersectionDistance(Ray r);

    Vector3D getCenter(){
        return centerOfSphere;
    }
    double getRadius(){
        return  radius;
    }

};


#endif //RAYTRACER_SPHERE_H
