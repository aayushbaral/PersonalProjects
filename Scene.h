//
// Created by click on 3/27/2016.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include "Sphere.h"
#include "Light.h"
#include <vector>
#include <memory>

class Scene {
public:
    Scene(){};
    void render(int width, int height);
    static std::vector<std::shared_ptr<Shape>> shapes;
    Color findColor(Vector3D intersectionPoint, double tIndex);
    static std::vector<std::shared_ptr<Light>>lights;
};


#endif //RAYTRACER_SCENE_H
