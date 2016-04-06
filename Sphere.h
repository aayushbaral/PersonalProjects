//
// Created by click on 3/27/2016.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H


#include "Color.h"
#include "Shape.h"
#include "Ray.h"
#include "Vector3D.h"

class Sphere: public Shape {
private:
    Color colorOfSphere;
    Vector3D centerOfSphere;
    double radius;

public:
    Sphere():Shape(0){};
    Sphere(float _ambience, Vector3D _center, Color _sphereColor, double _r):Shape(ambience){
        centerOfSphere = _center;
        colorOfSphere = _sphereColor;
        radius = _r;
        ambience = _ambience;
    }
    const Color getColor();
    const Vector3D getNormalFor(Vector3D intersectionPoint);
    const double getIntersectionDistance(Ray r);
    //const float getAmbience(){
        //return ambience;
    //};
    Vector3D getCenter(){
        return centerOfSphere;
    }
    double getRadius(){
        return  radius;
    }
};


#endif //RAYTRACER_SPHERE_H
