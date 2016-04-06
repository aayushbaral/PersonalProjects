//
// Created by click on 4/4/2016.
//

#ifndef RAYTRACER_DIRECTIONALLIGHT_H
#define RAYTRACER_DIRECTIONALLIGHT_H


#include "Light.h"

class DirectionalLight : public Light {
private:
    Vector3D directionOfLight;
public:
    DirectionalLight():Light(Color(0, 0, 0, 0)){};
    DirectionalLight(Vector3D _direction, Color _colorOfLight):Light(colorOfLight){
        directionOfLight = _direction;
        colorOfLight = _colorOfLight;

    }
    Vector3D getDirection(){
        return directionOfLight.unitVector();
    }
    const Vector3D getDirection(Vector3D intersectionPoint){
        return getDirection();
    }


};


#endif //RAYTRACER_DIRECTIONALLIGHT_H
