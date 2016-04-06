//
// Created by click on 4/4/2016.
//

#include "Camera.h"


Vector3D Camera::changeBasis(Vector3D a) {
    return a.getX() * u + a.getY() * v + a.getZ() * w;
}


