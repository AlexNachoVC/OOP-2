#include "Video.h"

using namespace std;

Video::Video() : id(0), nombre(""), duracion(0), genero(""), calificacion(0.0f) {}

Video::Video(int id, string nombre, int duracion, string genero) {
        this->id = id;
        this->nombre = nombre;
        this->duracion = duracion;
        this->genero = genero;
        this->calificacion = 0.0; 
}

int Video::getId() {
    return id;
}

string Video::getNombre() {
    return nombre;
}

int Video::getDuracion() {
    return duracion;
}

string Video::getGenero() {
    return genero;
}

float Video::getCalificacion() {
    return calificacion;
}

void Video::setCalificacion(float calificacion) {
    this->calificacion = calificacion;
}

void Video::mostrar() {
    cout << "ID: " << id << " | "
         << "Nombre: " << nombre << " | "
         << "Duracion: " << duracion << " | "
         << "Genero: " << genero << " | "
         << "Calificacion: " << calificacion << endl;
}