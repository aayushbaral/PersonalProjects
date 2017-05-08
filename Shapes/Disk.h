//
// Created by click on 3/28/2016.
//

#ifndef RAYTRACER_DISK_H
#define RAYTRACER_DISK_H


#include "Shape.h"

class Disk: public Shape {
private:
    Vector3D normal;
    Vector3D center;
    double radius;
    Color colorofDisk;
public:
    Disk():Shape(){};
    Disk(Vector3D _normal, Vector3D _center, double _radius, Color _colorofDisk, float _ambience, float _diffusedCoefficient, float _specularCoefficient):Shape(ambience,diffusedCoefficient, specularCoefficient ){
        normal = _normal;
        center = _center;
        radius = _radius;
        colorofDisk = _colorofDisk;
        ambience = _ambience;
        diffusedCoefficient = _diffusedCoefficient;
        specularCoefficient = _specularCoefficient;
    }
    const Vector3D getNormalFor(Vector3D intersectionPoint);
//Getters
    const Vector3D getNormal(){
        return normal;

    }
    const Vector3D getCeneter(){
        return center;
    }
    const double getRadius(){
        return radius;
    }




    const Color getColor();
    const double getIntersectionDistance(Ray r);

};


#endif //RAYTRACER_DISK_H
