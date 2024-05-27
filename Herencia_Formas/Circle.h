#pragma once
#include <cmath>
#include <iostream>

class Circle {
private: 
    float radius;

public: 
    Circle() {
        radius = 0;
    }
    ~Circle() {
    };

    bool setRadius(float nRadius);
    float getRadius();
    float calculatePerimeter();
    virtual float calculateArea();
};