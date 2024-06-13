#include "Gato.h"

Gato::Gato() {
    nombre = "";
    edad = 0;
}

Gato::Gato(string nombre, int edad) {
    this->nombre = nombre;
    this->edad = edad;
}

void Gato::hacerSonido() {
    cout << "Miau" << endl;
}

void Gato::describe() {
    cout << "\n";
    cout << "Gato" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}