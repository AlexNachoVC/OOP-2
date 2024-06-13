#pragma once
#include <iostream>
#include "Animal.h"

using namespace std;

class Perro : public Animal {
public:
    Perro();
    Perro(string nombre, int edad);

    void hacerSonido() override;  
    void describe() override;
};