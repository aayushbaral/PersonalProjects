//
// Created by click on 3/30/2016.
//

#ifndef RAYTRACER_BOX_H
#define RAYTRACER_BOX_H


#include "Shape.h"

class Box: public Shape{
private:
    Vector3D minBound;
    Vector3D maxBound;
    Color colorOfBox;
public:

    Box():Shape(){};
    Box(float _ambience, float _diffusedCoefficient, float  _specularCoefficient, Vector3D _minBound, Vector3D _maxBound,Color _colorOfBox): Shape(ambience, diffusedCoefficient, specularCoefficient){
        ambience = _ambience;
        minBound = _minBound;
        maxBound = _maxBound;
        colorOfBox = _colorOfBox;
        diffusedCoefficient = _diffusedCoefficient;
        specularCoefficient = _specularCoefficient;

    }
    const Color getColor();
    const double getIntersectionDistance(Ray r);
    const Vector3D getNormalFor(Vector3D intersectionPoint);

};



#endif //RAYTRACER_BOX_H
