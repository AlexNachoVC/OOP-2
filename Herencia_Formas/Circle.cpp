#include "Circle.h"

bool Circle::setRadius(float nRadius) {
    if (nRadius < 0) {
        return false;
    }
    radius = nRadius;
    return true;
}

float Circle::getRadius() {
    return radius;
}

float Circle::calculatePerimeter() {
    return 2*M_PI*radius;
}

float Circle::calculateArea() {
    return M_PI * (radius * radius);
}