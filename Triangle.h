//
// Created by click on 6/1/2016.
//

#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H


#include "Shape.h"

class Triangle: public Shape {
private:
    Vector3D position;
    Vector3D secondVertex;
    Vector3D thirdVertex;
    Color colorOfTriangle;
public:
    Triangle():Shape(){};
    Triangle(float _ambience, float _diffusedCoefficient, float _specularCoefficient, Vector3D _position, Vector3D _SecondVertex,

             Vector3D _thirdVertex, Color _triangleColor):Shape(_ambience, _diffusedCoefficient, _specularCoefficient){
        position = _position;
        secondVertex = _SecondVertex;
        thirdVertex = _thirdVertex;
        colorOfTriangle = _triangleColor;
    }
    Vector3D getPosition(){
        return  position;
    }
    Vector3D getSecondVertex(){
        return secondVertex;
    }
    Vector3D getThirdVertex(){
        return thirdVertex;
    }
    const Vector3D getNormalFor(Vector3D intersectionPoint);
    const double getIntersectionDistance(Ray ray);
    const Color getColor();



};


#endif //RAYTRACER_TRIANGLE_H
