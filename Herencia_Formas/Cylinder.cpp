#include "Cylinder.h"

bool Cylinder::setHeight(float nHeight) {
    if (nHeight < 0) {
        return false;
    }
    height = nHeight;
    return true;
}

float Cylinder::getHeight() {
    return height;
}

float Cylinder::calculateVolume() {
    return Circle::calculateArea() * height;
}

float Cylinder::calculateArea() {
    return 2 * M_PI * getRadius() *  getRadius() + 2 * M_PI * getRadius() * getHeight();
}