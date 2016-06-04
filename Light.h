//
// Created by click on 4/2/2016.
//

#ifndef RAYTRACER_LIGHT_H
#define RAYTRACER_LIGHT_H


#include "Color.h"
#include "Vector3D.h"
//Light as an abstract base class
class Light {
protected:
    Color colorOfLight;
public:
    Light(){};
    Light(Color _colorOfLight){
        colorOfLight = _colorOfLight;
    }
    virtual Vector3D getDirection(Vector3D intersectionPoint) = 0;
    Color getColorOfLight(){
        return colorOfLight;
    }



};


#endif //RAYTRACER_LIGHT_H
