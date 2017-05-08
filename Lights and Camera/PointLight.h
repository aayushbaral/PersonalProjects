//
// Created by click on 4/2/2016.
//

#ifndef RAYTRACER_POINTLIGHT_H
#define RAYTRACER_POINTLIGHT_H


#include "Light.h"

class PointLight : public Light {
private:
    Vector3D originOfLight;

public:
    PointLight():Light(Color(0, 0, 0, 0)){};

    PointLight(Vector3D _origin, Color _colorofLight):Light(_colorofLight){
        originOfLight = _origin;
    }

 Vector3D getDirection(Vector3D intersectionPoint) {
    Vector3D diff =  (intersectionPoint - getOrigin());
     Vector3D normalized = diff.unitVector();
     return normalized;

}
    Vector3D getOrigin(){
        return originOfLight;
    }






};


#endif //RAYTRACER_POINTLIGHT_H
