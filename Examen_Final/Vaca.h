#pragma once
#include <iostream>
#include "Animal.h"

using namespace std;

class Vaca : public Animal {
public:
    Vaca();
    Vaca(string nombre, int edad);

    void hacerSonido() override;  
    void describe() override;
};