//
// Created by click on 3/27/2016.
//

#include "Vector3D.h"
#include <cmath>

Vector3D::Vector3D(double _x, double _y, double _z) {
    x = _x;
    y = _y;
    z = _z;

}
double Vector3D::magnitudeOfVector() {
    return pow((pow(x, 2) + pow(y, 2) + pow(z, 2)), 0.5);

}

Vector3D Vector3D::crossProduct(Vector3D &vec1) {
    return Vector3D(vec1.getY() * this->getY() - vec1.getZ() * this->getY(),
    vec1.getZ() * this->getX() - vec1.getX() * this->getZ(),
    vec1.getX() * this->getY() - vec1.getY() * this->getX());


}

Vector3D Vector3D::unitVector() {
    return Vector3D(getX()/magnitudeOfVector(), getY()/magnitudeOfVector(), getZ()/magnitudeOfVector());
}

const double Vector3D::dotProduct(const Vector3D &vec1) const{
    return (vec1.getX() * this->getX() + vec1.getY() * this->getY() + vec1.getZ() * this->getZ());

}