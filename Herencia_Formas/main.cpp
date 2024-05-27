#include <iostream>
#include "Cylinder.h"

using namespace std;

#define NUM 10

int main() {
    Cylinder myCylinder[NUM];

    for (unsigned int i = 0; i < NUM; i++) {
        myCylinder[i].setRadius(i);
        myCylinder[i].setHeight(i);
    }
    for (unsigned int i = 0; i < NUM; i++) {
        cout << "Volume["<< i << "]: " << myCylinder[i].calculateVolume() << "\n"; 
    }
    return 0;
}