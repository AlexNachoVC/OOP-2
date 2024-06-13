#include "Perro.h"

Perro::Perro() {
    nombre = "";
    edad = 0;
}

Perro::Perro(string nombre, int edad) {
    this->nombre = nombre;
    this->edad = edad;
}

void Perro::hacerSonido() {
    cout << "Woof" << endl;
}

void Perro::describe() {
    cout << "\n";
    cout << "Perro" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}