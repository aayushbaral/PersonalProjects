//
// Created by click on 3/27/2016.
//

#include <memory>
#include <vector>

#include "Scene.h"
#include "ImageOutput.h"
#include "Compare.h"
#include <cstdlib>
#include <assert.h>


std::vector<std::shared_ptr<Shape>> Scene::shapes;
std::vector<std::shared_ptr<Light>> Scene::lights;

void Scene::render(int width, int height) {
    int resolution = height * width;
    Color *pixels = new Color[resolution];
    myCamera.setSample(1);
    myCamera.setAperture(18);
    myCamera.setFocalLength(5);

    //Vector3D focalPoint = myCamera.getPosition() + myCamera.getFocalLength() * Vector3D(-width/2, height/2, (height/2)/ tan((Options::cameraFOV *3.1416) /180));


    Compare randomNumber;
    int loopcounter = 0;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            Vector3D rayOrigin1 = Vector3D(i + (-width / 2) + 0.5, (height / 2) - j - 0.5, myCamera.getFocalLength());
            //Vector3D rayDirection = Vector3D(0,0,1);
            Vector3D rayOrigin = myCamera.getPosition();
            double zValueofRay = (height / 2) / tan((Options::cameraFOV * 3.1416) / 180);
            Color colorContribution = Color(0, 0, 0, 0);
            for (int l = 0; l < myCamera.getSample(); l++) {
                double  xOffset = (randomNumber.anyRandomGenerator(0, myCamera.getAperture())) * cos(randomNumber.anyRandomGenerator(0, 6.2832));
                double yOffset = (randomNumber.anyRandomGenerator(0, myCamera.getAperture())) * sin(randomNumber.anyRandomGenerator(0, 6.2832));
                Vector3D rayOriginforDof(myCamera.getPosition().getX() + xOffset, myCamera.getPosition().getY() + yOffset, myCamera.getPosition().getZ());
                Vector3D rayDirectionfordof = (rayOrigin1 - rayOriginforDof).unitVector();
                rayDirectionfordof = myCamera.changeBasis(rayDirectionfordof);
                Ray rayFordof(rayOriginforDof, rayDirectionfordof);
                double offset = randomNumber.anyRandomGenerator(0, 1);
                double xValueofRay = i + (-width) / 2 + offset;
                double yValueofRay = (height) / 2 - j + offset;
                Vector3D rayDirection = Vector3D(xValueofRay, yValueofRay, zValueofRay);
                rayDirection = myCamera.changeBasis(rayDirection).unitVector();
                //Ray ray(rayOriginforDof, rayDirectionfordof);
                Ray ray(rayOrigin, rayDirection);

                colorContribution = colorContribution + getColorfromRay(ray);
            }

            loopcounter++;
            Color average = colorContribution / myCamera.getSample();

            pixels[loopcounter] = average;

        }

    }
    ImageOutput::draw(height, width, pixels, "Sphere2.bmp");



}
    Color Scene::findColor(Vector3D intersectionPoint, double tIndex) {


            Color finalColor(0, 0, 0, 1);


        Color colorOfThisObject = Scene::shapes[tIndex]->getColor();
            double kd = 1 - Scene::shapes[tIndex]->getAmbience();

            Vector3D normal = Scene::shapes[tIndex]->getNormalFor(intersectionPoint);
            Matrix matrixTransposing = matrix.matrixTranspose(matrixTransposing);

            Matrix normalTransform  = matrix.matrixMultiplication(Scene::shapes[tIndex]->getInversetransformationMatrix(), matrixTransposing);
            Vector3D transformedNormal = Vector3D(normalTransform.matrix[0][0], normalTransform.matrix[0][1], normalTransform.matrix[0][2]);




            for (int i = 0; i < Scene::lights.size(); i++) {
                Vector3D raydirection = -Scene::lights[i]->getDirection(intersectionPoint);
                Vector3D rayOrigin = intersectionPoint + normal * 0.5;//0.5*


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
                //For specular lighting
                Vector3D eye = (myCamera.getPosition() - intersectionPoint).unitVector();
                Vector3D incidentLight = Scene::lights[i]->getDirection(intersectionPoint);
                //For reflected path
                Vector3D reflectedPath = incidentLight - 2 * normal * (normal.dotProduct(incidentLight));
                double specularFactor = eye.dotProduct(reflectedPath);
                if (specularFactor < 0) specularFactor = 0;
                specularFactor = pow(specularFactor, 50);
                specularFactor  = specularFactor * shapes[tIndex]->getSpecularccoefficient();
                Color colorOfThisLight = Scene::lights[i]->getColorOfLight();
                //For reflection
                Color reflectedRayColor;
                Ray reflectedRay = Ray(intersectionPoint, reflectedPath);
                reflectedRayColor = getColorfromRay(reflectedRay);
                double dotProduct = -Scene::lights[i]->getDirection(intersectionPoint).dotProduct(normal);
                double diffusedFactor = dotProduct * shapes[tIndex]->getDiffusedcoefficient();
                if (diffusedFactor < 0) diffusedFactor = 0;
                finalColor = finalColor + colorOfThisLight * colorOfThisObject * ((diffusedFactor + specularFactor));
            }
            return finalColor + colorOfThisObject * Scene::shapes[tIndex]->getAmbience();
        }

        Color Scene::getColorfromRay(Ray ray) {
            std::map<int, double> tContainer;
            Ray transformedRay;
            for (int k = 0; k < Scene::shapes.size(); k++) {
                Matrix  pointTransformation =  matrix.matrixMultiplication(Scene::shapes[k]->getInversetransformationMatrix(),
                ray.getOrigin().pointToMatrix(vector1));
                //Transforming the point

                Vector3D transformedPoint = Vector3D(pointTransformation.matrix[0][0],
                                                     pointTransformation.matrix[0][1],
                                                     pointTransformation.matrix[0][2]);
                //Transforming the direction
                Matrix directionTransformation = matrix.matrixMultiplication(Scene::shapes[k]->getInversetransformationMatrix(), ray.getDirection().vectorToMatrix(vector1));
                                                                                           ;

                Vector3D transformedDirection = Vector3D(directionTransformation.matrix[0][0], directionTransformation.matrix[0][1],
                                                            directionTransformation.matrix[0][2]);

                //t for transformation
                //double t = Scene::shapes[k]->getIntersectionDistance(transformedRay);
                double t = Scene::shapes[k]->getIntersectionDistance(ray);
                if (t > 0) tContainer[k] = t;
            }


            // make static method called  int findPositionOfMinPositiveValueFromMap(std::map tCont);
            int positionOfLowestT = Compare::findthepositionofMinValueofT(tContainer);
            if (positionOfLowestT != -1) {
                Vector3D intersectionPoint = ray.getOrigin() + ray.getDirection() * tContainer[positionOfLowestT];
                //For transformation
                //Vector3D intersectionPoint = transformedRay.getOrigin() + transformedRay.getDirection() * positionOfLowestT;



                return findColor(intersectionPoint, positionOfLowestT);
            }
            return Color(0, 0, 0, 0);
        }
