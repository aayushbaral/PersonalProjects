//
// Created by click on 3/27/2016.
//
#include "Ray.h"
#include "Sphere.h"
#include "Vector3D.h"
#include <iostream>


const Color Sphere::getColor() {
    return colorOfSphere;
}

const double Sphere::getIntersectionDistance(Ray r) {
    //Distance between the camera and the center of the sphere
    Vector3D A = getCenter() - r.getOrigin();
    Vector3D a = r.getDirection();
    double t1 = A.dotProduct(a);
    if (t1 < 0) {
        return -1;
    }
    double t2 = A.dotProduct(A) - t1 *  t1;
    if (t2 > radius * radius){
        return -1;
    }
    double d1 = sqrt(radius * radius - t2);
    double d0 = t1 - d1;
    double d2 = t1 + d1;
    if (d0 > d2){
        std::swap(d0, d2);
    }
    if (d0 < 0){
        d0 = d2;
        if (d0 <0){
            return -1;
        }
    }
    double  t = d0;
    return t;
}
const Vector3D Sphere::getNormalFor(Vector3D intersectionPoint) {
    return (intersectionPoint - getCenter()).unitVector();
}


