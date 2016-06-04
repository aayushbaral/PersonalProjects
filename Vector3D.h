//
// Created by click on 3/27/2016.
//

#ifndef RAYTRACER_VECTOR3D_H
#define RAYTRACER_VECTOR3D_H
#include <vector>
#include "Matrix.h"

using namespace std;


class Vector3D {
private:
    double x;
    double y;
    double z;
public:
    //Getters and setters for this class
    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    double getZ() const {
        return z;
    }

    void setX(double x) {
        x = x;

    }

    void setY(double y) {
        y = y;
    }

    void setZ(double z) {
        z = z;
    }

    //Constructor for this class
    Vector3D(double, double, double);
    Vector3D () {};
    const Vector3D unitVector();

    double magnitudeOfVector();

    Vector3D crossProduct(Vector3D &vec1);

    const double dotProduct(const Vector3D &vec1) const;
    Matrix vectorToMatrix(Vector3D a)const;
    Matrix pointToMatrix(Vector3D a)const;
    Vector3D matrixTovector(vector<vector<double>>);



};


    //Operators for this class
inline Vector3D operator+(const Vector3D &vec1, const Vector3D &vec2) {
        return Vector3D(vec1.getX() + vec2.getX(), vec1.getY() + vec2.getY(), vec1.getZ() + vec2.getZ());
    }
inline Vector3D operator-(const Vector3D &vec1){
    return Vector3D(-vec1.getX(), -vec1.getY(), -vec1.getZ());
}
inline Vector3D operator-(const Vector3D &vec1, const Vector3D &vec2){
    return Vector3D(vec1.getX() - vec2.getX(), vec1.getY() - vec2.getY(), vec1.getZ() - vec2. getZ());

}

inline Vector3D operator*(const Vector3D vec1, const double a){
    return Vector3D(a * vec1.getX(), a * vec1.getY(), a * vec1.getZ());

}
inline Vector3D operator/(const Vector3D vec1, const double a){
    return Vector3D(vec1.getX()/a, vec1.getY()/a, vec1.getZ()/a);
}
inline Vector3D operator*(const double a, const Vector3D &vec1){
    return Vector3D(a * vec1.getX(), a * vec1.getY(), a * vec1.getZ());}









#endif //RAYTRACER_VECTOR3D_H
