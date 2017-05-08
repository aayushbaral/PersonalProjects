//
// Created by click on 6/1/2016.
//

#ifndef RAYTRACER_MATRIX3X3_H
#define RAYTRACER_MATRIX3X3_H


#include "Vector3D.h"

class Matrix3X3 {
private:
    Vector3D vec1 = Vector3D(1, 0, 0);
    Vector3D vec2 = Vector3D(0, 1, 0);
    Vector3D vec3 = Vector3D(0, 0, 1);
public:
    //Constrictor for this class
    Matrix3X3(const Vector3D &vec1, const Vector3D &vec2, const Vector3D &vec3) : vec1(vec1), vec2(vec2), vec3(vec3) { };
   //Finding the determinant
    double determinant(){
        return ((vec1.getX() * vec2.getY() * vec3.getZ()) + (vec2.getX() * vec3.getY() *vec1.getZ()) +
                (vec3.getX() * vec1.getY() * vec2.getZ()) - (vec3.getX() * vec2.getY() * vec1.getZ()) -
                (vec2.getX() * vec1.getY() * vec3.getZ()) -
                (vec1.getX() * vec3.getY() * vec2.getZ()));
    }

};


#endif //RAYTRACER_MATRIX3X3_H
