//
// Created by click on 3/27/2016.
//

#include <memory>
#include "Scene.h"
#include "ImageOutput.h"
#include "Sphere.h"
#include "Plane.h"
#include "Compare.h"
#include "Light.h"
#include "PointLight.h"
#include "Camera.h"
#include "Options.h"
#include <map>
#include <assert.h>

std::vector<std::shared_ptr<Shape>> Scene::shapes;
std::vector<std::shared_ptr<Light>> Scene::lights;


void Scene::render(int width, int height) {
    Camera myCamera(Options::cameraLookAt, Options::cameraPosition, Options::cameraFOV);
    int resolution = height * width;
    Color *pixels = new Color[resolution];
    int loopcounter = 0;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            //Vector3D rayOrigin = Vector3D(i + (-width / 2) + 0.5, (height / 2) - j - 0.5, -500);
            //Vector3D rayDirection = Vector3D(0,0,1);
            Vector3D rayOrigin = myCamera.getPosition();
            Vector3D rayDirection = (Vector3D( i + (-width)/2, (height)/2 -j, (height/2)/tan((Options::cameraFOV * 3.1416)/180))).unitVector();
            rayDirection = myCamera.changeBasis(rayDirection).unitVector();
            Ray ray(rayOrigin, rayDirection);
            loopcounter++;
            std::map<int, double> tContainer;
            for (int k = 0; k < Scene::shapes.size(); k++){
                double t = Scene::shapes[k]->getIntersectionDistance(ray);
                if (t > 0 ) tContainer[k] = t;
            }

            // make static method called  int findPositionOfMinPositiveValueFromMap(std::map tCont);
            int positionOfLowestT = Compare::findthepositionofMinValueofT(tContainer);
            if (positionOfLowestT != -1) {
                Vector3D intersectionPoint = rayOrigin + rayDirection * tContainer[positionOfLowestT];
                pixels[loopcounter - 1] = findColor(intersectionPoint, positionOfLowestT);
            }
        }
    }

    ImageOutput::draw(height, width, pixels, "Sphere.bmp");
}
Color Scene::findColor(Vector3D intersectionPoint, double tIndex) {

    Color finalColor(0, 0, 0, 1);
    Color colorOfThisObject = Scene::shapes[tIndex]->getColor();
    double kd = 1 - Scene::shapes[tIndex]->getAmbience();

    Vector3D normal = Scene::shapes[tIndex]->getNormalFor(intersectionPoint);

    for (int i = 0; i < Scene::lights.size(); i++) {
        Vector3D raydirection = -Scene::lights[i]->getDirection(intersectionPoint);
        Vector3D rayOrigin = intersectionPoint + normal * 0.5;
        Ray ray(rayOrigin, raydirection);

        bool isShadowed = false;
        for (int k = 0; k < shapes.size(); k++) {
            if (k == tIndex) continue;
            double t = Scene::shapes[k]->getIntersectionDistance(ray);
            if (t > 0) {
                isShadowed = true;
                break;
            }
        }
        if (isShadowed) continue;

        Color colorOfThisLight = Scene::lights[i]->getColorOfLight();
        double dotProduct = -Scene::lights[i]->getDirection(intersectionPoint).dotProduct(normal);
        if (dotProduct < 0) dotProduct = 0;
        finalColor = finalColor + colorOfThisLight * colorOfThisObject * (kd * dotProduct);
    }
    return finalColor + colorOfThisObject * Scene::shapes[tIndex]->getAmbience();
}












