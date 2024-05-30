
#include "ArregloComplejos.h"

ArregloComplejos::ArregloComplejos() {
    indiceActual = 0;
}

bool ArregloComplejos::agregar(NumComplejo num) {
    if (indiceActual >= 6) {
        return false; 
    }

    arreglo[indiceActual] = num;
    indiceActual++;
    return true; 
}


NumComplejo ArregloComplejos::sumaTotal() {
    NumComplejo suma;
    for (int i = 0; i < indiceActual; i++) {
        suma = NumComplejo::sumaComplejo(suma, arreglo[i]);
    }
    return suma;
}