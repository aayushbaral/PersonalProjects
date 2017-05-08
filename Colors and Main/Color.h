//
// Created by click on 3/27/2016.
//
#pragma once
#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H
#include <cmath>
#include <stdint.h>


class Color {
private:
    double r;
    double b;
    double g;
    double a;

public:
    //Empty Constructor
    Color(){};

    //Getters and Setters
    const double getR() const {
        return r;
    }

    const double getB() const{
        return b;

    }

    const double getG() const{
        return g;

    }

    const double getA() const {
        return a;
    }

    Color(double _r, double _g, double _b, double _a){
        r = _r;
        b = _b;
        g = _g;
        a = _a;
    }
    const uint8_t  getRedInt(){
        return (uint8_t)(floor)(pow(getR(),(0.5 * 2)) * 255);
    }
    const  uint8_t getBlueInt(){
        return (uint8_t)(floor)(pow(getB(),(0.5 * 2)) * 255);
    }
     const uint8_t getGreenInt(){
        return (uint8_t)(floor)(pow(getG(),(0.5 * 2)) * 255);
    }
    const uint8_t  getAlphaInt(){
        return (uint8_t)(floor)(pow(getA(),(0.5 * 2)) * 255);
    }
};
//Operator overloading for this class

inline Color operator+(const Color &col1, const Color &col2) {
    return Color(col1.getR() + col2.getR(), col1.getB() + col2.getB() , col1.getG() + col2.getG(), col1.getA() + col2.getA());
}

inline Color operator*(const Color &col1, double t){
    return Color(col1.getR() * t, col1.getB() * t, col1.getG() * t, col1.getA() * t);
}
//dubai way

//color * color
inline Color operator*(const Color &col1, const Color &col2){
    return Color(col1.getR() * col2.getR(), col1.getB() * col2.getB(), col1.getG() * col2.getG(), col1.getA() * col2.getA());
}
inline Color operator/(const Color &col1, const double t){
    return Color(col1.getR() / t, col1.getB() / t, col1.getG() / t, col1.getA() /t );
}

#endif //RAYTRACER_COLOR_H
