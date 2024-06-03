#include <iostream>
#include "cylinder.h"

using namespace std;

#define NUM 4

int main() {
    Cylinder myCylinder[NUM];
    
    for(unsigned int i = 0; i < NUM; i++) {
        myCylinder[i].setRadius(i);
        myCylinder[i].setHeight(i);
    }

    for(unsigned int i = 0; i < NUM; i++) {
        myCylinder[i].displayData();
    }

    return 0;
}
