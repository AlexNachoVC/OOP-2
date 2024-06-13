#pragma once
#include <iostream>
#include "Animal.h"

using namespace std;

class Gato : public Animal {
public:
    Gato();
    Gato(string nombre, int edad);

    void hacerSonido() override;  
    void describe() override;
};