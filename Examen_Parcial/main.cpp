#include <iostream>
#include "ArregloComplejos.h"

int main() {
    ArregloComplejos arreglo;

    for (unsigned int index = 0; index < 10; index++) {
        NumComplejo tmp(index, index + 1);

        arreglo.agregar(tmp);
    }

    NumComplejo sumaTotal = arreglo.sumaTotal();
    std::cout << "La suma total de los complejos en el arreglo es: ";
    sumaTotal.imprimir();

    return 0;
}
