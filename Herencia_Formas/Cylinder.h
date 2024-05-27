#pragma once
#include <cmath>
#include "Circle.h"

class Cylinder : public Circle {
private:
    float height;

public:
    Cylinder() {
        height = 0;
    }
    ~Cylinder() {
    };

    bool setHeight(float nHeight);
    float getHeight();
    float calculateVolume();
    float calculateArea() override;
};