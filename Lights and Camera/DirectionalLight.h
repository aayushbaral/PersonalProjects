//
// Created by click on 4/4/2016.
//

#ifndef RAYTRACER_DIRECTIONALLIGHT_H
#define RAYTRACER_DIRECTIONALLIGHT_H


#include "Light.h"
//Using Light as an abstract base class

class DirectionalLight : public Light {
private:
    Vector3D directionOfLight;
public:
    //setting the constructor to color black
    DirectionalLight():Light(Color(0, 0, 0, 0)){};
    DirectionalLight(Vector3D _direction, Color _colorOfLight):Light(colorOfLight){
        directionOfLight = _direction;
        colorOfLight = _colorOfLight;

    }
    Vector3D getDirection(){
        return directionOfLight.unitVector();
    }
    Vector3D getDirection(Vector3D intersectionPoint){
        return getDirection();
    }


};


#endif //RAYTRACER_DIRECTIONALLIGHT_H
