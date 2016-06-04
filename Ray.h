//
// Created by click on 3/27/2016.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H
#include <vector>
#include <cmath>
#include "Vector3D.h"

using namespace std;

class Ray {
private:
 Vector3D origin;
    Vector3D direction;
public:

    Ray(const Vector3D &origin, const Vector3D &direction) : origin(origin), direction(direction) { }
    Ray(): origin(Vector3D()), direction(Vector3D()){}
    const Vector3D &getOrigin() const {
        return origin;
    }

    void setOrigin(const Vector3D &origin) {
        Ray::origin = origin;
    }

    const Vector3D &getDirection(){
        return direction;
    }

    void setDirection(const Vector3D &direction) {
        Ray::direction = direction;
    }
};


#endif //RAYTRACER_RAY_H
