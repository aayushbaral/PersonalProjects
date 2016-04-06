//
// Created by click on 3/27/2016.
//

#include "Plane.h"


const Color Plane::getColor() {
    return colorOfplane;
}
const double Plane::getIntersectionDistance(Ray r){
    double a = normal.dotProduct(r.getDirection());
    if (a == 0) return -1;
    double t = ((getPoint() - r.getOrigin()).dotProduct(normal)) / a;
    return t <= 0 ? -1 : t;
}

const Vector3D Plane::getNormalFor(Vector3D intersectionPoint) {
    return getNormal();
}