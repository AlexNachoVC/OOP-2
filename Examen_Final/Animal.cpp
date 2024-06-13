#include "Animal.h"

Animal::Animal() {
    nombre = "";
    edad = 0;
}

Animal::Animal(string nombre, int edad) {
    this->nombre = nombre;
    this->edad = edad;
}

string Animal::getNombre() {
    return nombre;
}

int Animal::getEdad() {
    return edad;
}

void Animal::setNombre(string nombre) {
    this->nombre = nombre;
}

void Animal::setEdad(int edad) {
    this->edad = edad;
}

