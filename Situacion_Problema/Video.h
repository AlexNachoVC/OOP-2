#pragma once
#include <iostream>

using namespace std;

class Video {
protected: 
    int id;
    string nombre;
    int duracion;
    string genero;
    float calificacion;

public: 
    Video();
    Video(int id, string nombre, int duracion, string genero);
    int getId();
    string getNombre();
    int getDuracion();
    string getGenero();
    float getCalificacion();
    void setCalificacion(float calificacion);
    virtual void mostrar();
};