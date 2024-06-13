#include "Vaca.h"

Vaca::Vaca() {
    nombre = "";
    edad = 0;
}

Vaca::Vaca(string nombre, int edad) {
    this->nombre = nombre;
    this->edad = edad;
}

void Vaca::hacerSonido() {
    cout << "Muuuu" << endl;
}

void Vaca::describe() {
    cout << "\n";
    cout << "Vaca" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}