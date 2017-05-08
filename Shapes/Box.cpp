//
// Created by click on 3/30/2016.
//

#include "Box.h"
#include <memory>
#include <iostream>

const Color Box::getColor() {
    return colorOfBox;
}
const double Box::getIntersectionDistance(Ray r) {
    double txMin = (minBound.getX() - r.getOrigin().getX())/(r.getDirection().getX());
    double txMax = (maxBound.getX()-r.getOrigin().getX())/(r.getDirection().getX());
    double tyMin = (minBound.getY() - r.getOrigin().getY())/(r.getDirection().getY());
    double tyMax = (maxBound.getY() - r.getOrigin().getY())/ (r.getDirection().getY());
    double tzMax = (maxBound.getZ() - r.getOrigin().getZ())/ (r.getDirection().getZ());
    double tzMin = (minBound.getZ() - r.getOrigin().getZ())/ (r.getDirection().getZ());

    if (txMin > txMax) std::swap(txMin, tyMax);
    if(tyMin > tyMax) std::swap(tyMin, tyMax);
    if(tzMin > tzMax) std::swap(tzMin, tzMax);

    double t = txMin;

    if((txMin > tyMax) || (tyMin > txMax)) return -1;
    if (tyMin > t)  t = tyMin;
    if ((txMin > tzMax) || (tzMin > txMax)) return -1;
    if ((tyMin > tzMax) || (tzMin > tyMax)) return -1;
    if (tzMin > t) t = tzMin;
    return t;
}
const Vector3D Box::getNormalFor(Vector3D intersectionPoint){
    if (intersectionPoint.getX() == minBound.getX()){
        return Vector3D (-1, 0,0);
    }
    if (intersectionPoint.getX() == maxBound.getX()){
        return Vector3D(1, 0 ,0);
    }
    if (intersectionPoint.getY() == minBound.getY()){
        return Vector3D (0 , -1, 0);

    }
    if (intersectionPoint.getY() == maxBound.getY()){
        return Vector3D (0, 1, 0);
    }
    if (intersectionPoint.getZ() == minBound.getZ()){
        return  Vector3D (0, 0, -1);
    }
    if (intersectionPoint.getZ() == maxBound.getZ()){
        return Vector3D (0, 0, 1);
    }
}
