
#include <iostream>
#include "Vector3D.h"
#include "Sphere.h"
#include "Scene.h"
#include "Plane.h"
#include "Disk.h"
#include "Box.h"
#include "PointLight.h"
#include "DirectionalLight.h"
#include "Options.h"


using namespace std;


int main() {
   // Vector3D cameraDirection = (diff.UnitVector());
// std::vector
// std::vector
    //include <vector>

    //using with UDTs

    //shared pointer is used

    //Insert a sphere

    Scene::shapes.push_back(make_shared<Sphere>(0.4, Vector3D(0,35,0), Color(1,0,0,0.5), 18));

    //Scene::shapes.push_back(make_shared<Sphere>(0.4, Vector3D(50,35,0), Color(0,1,0,0.5), 18));
    //Scene::shapes.push_back(make_shared<Disk>( Vector3D(0, 0, 1),Vector3D(0, 0, 15), 100, Color(0.4, 0.1, 0, 0), 0.4));

    Scene::shapes.push_back(make_shared<Plane>(0.4, Vector3D(0,1,0), Vector3D(0,0,-10), Color(0.5,0.5,0.5,0.5)));
    //Scene::shapes.push_back(make_shared<Box>(0.4, Vector3D(-100, 100, -100), Vector3D(12, 12, 12),Color(0.3, 0.5, 0, 0)));
    Scene::lights.push_back(make_shared<PointLight>(Vector3D (-10, 100 , -40), Color(1, 1, 1, 1)));
    Scene::lights.push_back(make_shared<DirectionalLight>(Vector3D (1, 1, 10), Color (1, 1, 0.5, 0)));
    //Scene::lights.push_back(make_shared<PointLight>(Vector3D(-10, 100, -40), Color(1, 1, 1, 1)));

    Scene firstScene;
    Options::cameraLookAt = Vector3D(0,0,0);
    Options::cameraPosition = Vector3D(3,40,-40);
    
    Options::cameraFOV = 52;

    firstScene.render(400,400);
    return 0;
}