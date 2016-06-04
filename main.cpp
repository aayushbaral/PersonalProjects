

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
#include "Compare.h"
#include "Camera.h"
#include "Triangle.h"
#include <cstdlib>
#include <time.h>


using namespace std;


int main() {
    srand((unsigned int)time(NULL));
    //using with UDTs
    //shared pointer is used
    //Insert a sphere
    Scene::shapes.push_back(make_shared<Sphere>(0.1,0.8, 0.1, Vector3D(5, 0, 0), Color(1, 0.2, 0, 1), 4));

    //Scene::shapes.push_back(make_shared<Sphere>(0.2,0.5, 0.3, Vector3D(-10,10,-2), Color(0.7,0.5,0.3,1), 3));
    //Scene::shapes.push_back(make_shared<Triangle>(0.3, 0.5, 0.3, Vector3D(0, 0, 0),Vector3D(10, 0, 0), Vector3D(0, 10, 0), Color(1, 0.2, 0, 1)));
    //Scene::shapes.push_back(make_shared<Disk>( Vector3D(0, 0, 1),Vector3D(0, 0, 15), 100, Color(0.4, 0.1, 0, 0), 0.4));

    //Scene::shapes.push_back(make_shared<Plane>(0.4,0.5, 0.6, Vector3D(0, 1, 0), Vector3D(0, 0, -10), Color(0.5, 0.5, 0.5, 0.5)));
    //Scene::shapes.push_back(make_shared<Box>(0.4, Vector3D(-100, 100, -100), Vector3D(12, 12, 12),Color(0.3, 0.5, 0, 0)));
    Scene::lights.push_back(make_shared<PointLight>(Vector3D(10, 10, -50), Color(1, 1, 1, 1)));
    //Scene::lights.push_back(make_shared<DirectionalLight>(Vector3D(1, 1, 10), Color(1, 1, 0.5, 0)));
    //Scene::lights.push_back(make_shared<PointLight>(Vector3D(-10, 100, -40), Color(1, 1, 1, 1)));

    Options::cameraLookAt = Vector3D(0, 0, 0);
    Options::cameraPosition = Vector3D(0, 0, -15);

    Options::cameraFOV = 50;

    Scene firstScene;

    firstScene.render(600, 600);



}
