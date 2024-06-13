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

    void setId(string id);
    void setNombre(string nombre);
    void setDuracion(int duracion);
    void setGenero(string genero);
    void setCalificacion(float calificacion);
    
    virtual void mostrar() = 0; // Funcion virtual pura, ya que se implementa de diferente manera en cada una de las clases derivadas.
};