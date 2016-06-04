//
// Created by click on 3/28/2016.
//

#include "Disk.h"
#include "Plane.h"

const Color Disk::getColor() {
    return colorofDisk;

}
//Getting ray intersection distance for disk
const double Disk::getIntersectionDistance(Ray r) {
    Plane myPlane(ambience,diffusedCoefficient, specularCoefficient,  normal, center, Color());
    double t = myPlane.getIntersectionDistance(r);
    if (t == -1) return -1;
    Vector3D intersectionPoint = r.getOrigin() + r.getDirection() * t;
    double magnitude = (intersectionPoint - center).magnitudeOfVector();
    if (magnitude <= radius) return t;
    return -1;
}
const Vector3D Disk::getNormalFor(Vector3D intersectionPoint) {
    return getNormal();
}

//
