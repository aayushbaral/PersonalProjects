//
// Created by click on 3/27/2016.
//

#include "Ray.h"
#include "Vector3D.h"


Ray::Ray(const Vector3D _o, const Vector3D _d) {
    direction = _d;
    origin = _o;
}