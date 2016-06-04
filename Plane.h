//
// Created by click on 3/27/2016.
//

#pragma once
#ifndef RAYTRACER_PLANE_H
#define RAYTRACER_PLANE_H
#include "Shape.h"



class Plane: public Shape {
private:
    Vector3D normal;
    Color colorOfplane;
    Vector3D point;



public:
    Plane():Shape(){};
    //Setting the ambience, diffusedcoefficient and specular coefficient to the abstract base class
    Plane(float _ambience, float _diffusedCoefficient, float _specularCoefficient, Vector3D _normal, Vector3D pointOnPlane, Color planeColor):Shape(ambience, diffusedCoefficient, specularCoefficient){
        normal = _normal;
        colorOfplane = planeColor;
        point = pointOnPlane;
        ambience = _ambience;
        diffusedCoefficient = _diffusedCoefficient;
        specularCoefficient = _specularCoefficient;

    }
    //Getters
    const Vector3D getPoint(){
        return point;


    }
    const Vector3D getNormal(){
        return normal;
    }

    const Color getColor();
    const double getIntersectionDistance(Ray r);
    const Vector3D getNormalFor(Vector3D intersectionPoint);



};


#endif //RAYTRACER_PLANE_H
