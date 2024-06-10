#include "Pelicula.h"

using namespace std;

Pelicula::Pelicula() : Video("", "", 0, "", 0.0) {}

Pelicula::Pelicula(string id, string nombre, int duracion, string genero, float calificacion) : Video(id, nombre, duracion, genero, calificacion)
{
}

void Pelicula::mostrar() {
    cout << "ID Pelicula: " << id << " | "
         << "Nombre Pelicula: " << nombre << " | "
         << "Duracion Pelicula: " << duracion << " | "
         << "Genero Pelicula: " << genero << " | "
         << "Calificacion Pelicula: " << calificacion << endl;
}

void Pelicula::setId(string id) { 
    this->id = id;
}
void Pelicula::setNombre(string nombre) { 
    this->nombre = nombre; 
}
void Pelicula::setDuracion(int duracion) { 
    this->duracion = duracion; 
}
void Pelicula::setGenero(string genero) { 
    this->genero = genero; 
}
void Pelicula::setCalificacion(float calificacion) { 
    this->calificacion = calificacion; 
}