//
// Created by click on 3/27/2016.
//

#ifndef RAYTRACER_PLANE_H
#define RAYTRACER_PLANE_H
#include "Vector3D.h"
#include "Color.h"
#include "Ray.h"
#include "Shape.h"

class Plane: public Shape {
private:
    Vector3D normal;
    Color colorOfplane;
    Vector3D point;



public:
    Plane():Shape(0){};
    Plane(float _ambience, Vector3D _normal, Vector3D pointOnPlane, Color planeColor):Shape(ambience){
        normal = _normal;
        colorOfplane = planeColor;
        point = pointOnPlane;
        ambience = _ambience;

    }
    //Getters
    const Vector3D getPoint(){
        return point;


    }
    const Vector3D getNormal(){
        return normal;
    }

    const Color getColor();
    const double getIntersectionDistance(Ray r);
    const Vector3D getNormalFor(Vector3D intersectionPoint);



};


#endif //RAYTRACER_PLANE_H
