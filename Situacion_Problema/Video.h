#pragma once
#include <iostream>

using namespace std;

class Video {
protected: 
    string id;
    string nombre;
    int duracion;
    string genero;
    float calificacion;

public: 
    Video();
    Video(string id, string nombre, int duracion, string genero, float calificacion);
    string getId();
    string getNombre();
    int getDuracion();
    string getGenero();
    float getCalificacion();
    void setCalificacion(float calificacion);
    virtual void mostrar();
};