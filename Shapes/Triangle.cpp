//
// Created by click on 6/1/2016.
//

#include "Triangle.h"
#include "Matrix3X3.h"

const Color Triangle::getColor() {
    return colorOfTriangle;
}

const Vector3D Triangle::getNormalFor(Vector3D intersectionPoint) {
    Vector3D firstAdjacentdifference = (secondVertex - position);
    Vector3D secondAdjacentdifference= (thirdVertex - position);
    Vector3D normal = (firstAdjacentdifference.crossProduct(secondAdjacentdifference).unitVector());
    return normal;
}
const double Triangle::getIntersectionDistance(Ray ray) {
    Matrix3X3 A = Matrix3X3( Vector3D(position.getX() - secondVertex.getX(), position.getY() - secondVertex.getY(), position.getZ() - secondVertex.getZ()), Vector3D(position.getX() - thirdVertex.getX(), position.getY() - thirdVertex.getY(), position.getZ() - thirdVertex.getZ()),  Vector3D(ray.getDirection().getX(), ray.getDirection().getY(), ray.getDirection().getZ()));

    Matrix3X3 B = Matrix3X3(Vector3D(position.getX() - ray.getOrigin().getX(), position.getY() - ray.getOrigin().getY(), position.getZ() - ray.getOrigin().getZ()), Vector3D(position.getX() - thirdVertex.getX(), position.getY() -
            thirdVertex.getY(), position.getZ() - thirdVertex.getZ()), Vector3D(ray.getDirection().getX(), ray.getDirection().getY(), ray.getDirection().getZ()));

    Matrix3X3 C = Matrix3X3(Vector3D(position.getX() - secondVertex.getX(), position.getY() - secondVertex.getY(), position.getZ() -
            secondVertex.getZ()), Vector3D(position.getX() - ray.getOrigin().getX(), position.getY() - ray.getOrigin().getY(), position.getZ() - ray.getOrigin().getZ()),
                            Vector3D(ray.getDirection().getX(), ray.getDirection().getY(), ray.getDirection().getZ()));


    double beta = (B.determinant()) / (A.determinant());

    double gamma = (C.determinant()) / (A.determinant());

    if ((beta + gamma) > 1)
        return -1;



    double alpha = 1 - (beta + gamma);

    if ((0 < alpha && alpha < 1) && (0 < beta && beta < 1) && (0 < gamma && gamma < 1) && (beta + gamma) < 1 && (alpha + beta) < 1 && (alpha + gamma) < 1)
    {
        Matrix3X3 D = Matrix3X3(Vector3D(position.getX() - secondVertex.getX(), position.getY() - secondVertex.getY(), position.getZ() - secondVertex.getZ()), Vector3D(position.getX() - thirdVertex.getX(), position.getY() - thirdVertex.getY(), position.getZ()
                                                                                                                                                                                                                                                    - thirdVertex.getZ()), Vector3D(position.getX() - ray.getOrigin().getX(), position.getY() - ray.getOrigin().getY(), position.getZ() - ray.getOrigin().getZ()));

        double t = (D.determinant()) / (A.determinant());
        return t;
    }
    return -1;
}
