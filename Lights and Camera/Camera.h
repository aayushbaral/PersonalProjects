//
// Created by click on 4/4/2016.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H


#include "Vector3D.h"

class Camera {
private:
    Vector3D originOfCamera;
    Vector3D lookat, u, v, w;
    double fov;
    int numberOfSamples;
    double aperture;
    double focalLength;
public:
    Camera(){};
    Camera(Vector3D _lookat, Vector3D _position, double _fov) {
        lookat = _lookat;
        originOfCamera = _position;
        fov = _fov;
        //getting cameradirection
        Vector3D camDirection = (getlookAt() - getPosition());
        w = camDirection.unitVector();
        u=  Vector3D(0, 1, 0).crossProduct(w);
        v = w.crossProduct(u);//left right

    }
    Vector3D getlookAt(){
        return  lookat;
    }
    Vector3D getPosition(){
        return  originOfCamera;
    }
    double getFov(){
        return fov;
    }
    void setSample(int _samples){
        numberOfSamples = _samples;
    }
    int getSample(){
        return numberOfSamples;    }


    void setAperture(double _aperture){
        aperture = _aperture;
    }
    double getAperture(){
        return aperture;
    }
    //setting focal lengths

    void setFocalLength(double _focal){
        focalLength = _focal;
    }
    double getFocalLength(){
        return focalLength;
    }


    Vector3D changeBasis(Vector3D a);








};


#endif //RAYTRACER_CAMERA_H

