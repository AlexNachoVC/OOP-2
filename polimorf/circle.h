#pragma once
#include <iostream>

class Circle {
protected:
    float radius;
public:
    Circle() {
        radius = 0;
        std::cout << "Constructor Circle\n";
    }
    ~Circle() {
        std::cout << "Destructor Circle\n";
    };

    bool setRadius(float nRadius);
    float getRadius();
    virtual void displayData();
};
