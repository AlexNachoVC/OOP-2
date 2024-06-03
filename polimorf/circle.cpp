#include "circle.h"

bool Circle::setRadius(float nRadius) {
    if(nRadius < 0)
        return false;
    radius = nRadius;
    return true;
}

float Circle::getRadius() {
    return radius;
}

void Circle::displayData() {
    std::cout << "Soy un Circle con radius: " << radius << "\n";
}
