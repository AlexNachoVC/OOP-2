#include "Pelicula.h"

using namespace std;

Pelicula::Pelicula(int id, string nombre, int duracion, string genero): Video(id, nombre, duracion, genero) {

}

void Pelicula::mostrar() {
    cout << "ID Pelicula: " << id << " | "
         << "Nombre Pelicula: " << nombre << " | "
         << "Duracion Pelicula: " << duracion << " | "
         << "Genero Pelicula: " << genero << " | "
         << "Calificacion Pelicula: " << calificacion << endl;
}