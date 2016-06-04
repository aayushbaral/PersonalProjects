//
// Created by click on 3/27/2016.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H


#include "Light.h"
#include <vector>
#include <memory>
#include "Ray.h"
#include "Camera.h"
#include "Options.h"
#include "Shape.h"
#include "PointLight.h"

class Scene {
public:
    Scene(){
        myCamera = Camera(Options::cameraLookAt, Options::cameraPosition, Options::cameraFOV);
    };
    void render(int width, int height);
    static std::vector<std::shared_ptr<Shape>> shapes;
    Color findColor(Vector3D intersectionPoint, double tIndex);
    static std::vector<std::shared_ptr<Light>>lights;

    Color getColorfromRay(Ray ray);
private:
    Matrix matrix;
    Vector3D vector1;
    Camera myCamera;
    PointLight myLight;
};


#endif //RAYTRACER_SCENE_H
