#pragma once
#include "NumComplejo.h"

class ArregloComplejos {
private:
    NumComplejo arreglo[6];
    int indiceActual;

public:
    ArregloComplejos();

    bool agregar(NumComplejo num);
    NumComplejo sumaTotal();
};