#pragma once
#include <iostream> 

using namespace std;

class Animal {
protected:
    string nombre;
    int edad;

public:
    Animal();
    Animal(string nombre, int edad);

    string getNombre();
    int getEdad();

    void setNombre(string nombre);
    void setEdad(int edad);

    virtual void hacerSonido() = 0;
    virtual void describe() = 0;
};