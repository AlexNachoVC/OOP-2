#pragma once
#include <iostream>
#include "Video.h"

using namespace std;

class Pelicula : public Video {
public:
    Pelicula(int id, string nombre, int duracion, string genero);
    void mostrar();
};