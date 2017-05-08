//
// Created by click on 3/28/2016.
//

#ifndef RAYTRACER_COMPARE_H
#define RAYTRACER_COMPARE_H
#include <map>


class Compare {
public:
    Compare(){};
    static int findthepositionofMinValueofT(std::map<int, double> myMap);
    double randomNumberGenerator();
    double anyRandomGenerator(double _minvalue, double _maxvalue);





};


#endif //RAYTRACER_COMPARE_H
