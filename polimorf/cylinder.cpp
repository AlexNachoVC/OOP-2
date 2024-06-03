#include "cylinder.h"

bool Cylinder::setHeight(float height) {
    if(height < 0)
        return false;
    this->height = height;
    return true;
}

float Cylinder::getHeight() {
    return height;
}

void Cylinder::displayData() {
    std::cout << "Soy un Cylinder con radius: " << radius << " y height: " << height << "\n";
}


