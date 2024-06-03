#pragma once
#include <iostream>
#include "circle.h"

class Cylinder : public Circle {
private:
    float height;
public:
    Cylinder() {
        height = 0;
        std::cout << "Constructor Cylinder\n";
    }
    ~Cylinder() {
        std::cout << "Destructor Cylinder\n";
    };

    bool setHeight(float nRadius);
    float getHeight();
    void displayData() override;
};
