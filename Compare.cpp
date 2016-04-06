//
// Created by click on 3/28/2016.
//

#include "Compare.h"
#include <map>
#include "Scene.h"
int Compare::findthepositionofMinValueofT(std::map<int, double> myMap ) {

    if (myMap.size() == 0) return -1;
    double min = 1000000000;
    int positionOfLowestT = 0;

    for (std::map<int, double>::iterator it = myMap.begin(); it != myMap.end(); ++it){
        if (it->second < min) {
            min = it->second;
            positionOfLowestT = it->first;
        }
    }
    return positionOfLowestT;

}


