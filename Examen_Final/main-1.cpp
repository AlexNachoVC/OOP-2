#include <iostream>
// Incluye aqu� los archivos que necesites
#include "Perro.h"
#include "Gato.h"
#include "Vaca.h"

using namespace std;


void printDetails(Animal* animal) {
    animal->describe();
    animal->hacerSonido();
}


int main() {
    // Completa aqu� la Parte 1
    Perro perro1("Bimba", 6);
    Gato gato1("Misifus", 1);
    Vaca vaca1("Lechera", 10);

    cout << "Parte 2:\n";
    // Completa aqu� la Parte 2
    printDetails(&perro1);
    printDetails(&gato1);
    printDetails(&vaca1);

    cout << "Parte 3:\n";
    // Completa aqu� la Parte 3
    Animal* animales[3];
    animales[0] = &perro1;
    animales[1] = &gato1;
    animales[2] = &vaca1;

    cout << "Parte 4:\n";
    // Completa aqu� la Parte 4
    int edad_Ingresada;
    for (int i = 0; i < 3; i++) {
        cout << "Ingrese la edad que quiere poner a los animales: " << endl;
        cin >> edad_Ingresada;
        animales[i]->setEdad(edad_Ingresada);
    }

    cout << "Parte 5:\n";
    // Completa aqu� la Parte 5
    for (int i = 0; i < 3; i++) {
        animales[i]->describe();
    }

    return 0;
}

