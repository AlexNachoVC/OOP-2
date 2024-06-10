#pragma once
#include <iostream>
#include "Video.h"

using namespace std;

class Pelicula : public Video {
public:
    Pelicula();
    Pelicula(int id, string nombre, int duracion, string genero, float calificacion);
    void mostrar();
    void setId(int id);
    void setNombre(string nombre);
    void setDuracion(int duracion);
    void setGenero(string genero);
    void setCalificacion(float calificacion);
};