#pragma once
#include "Video.h"

class Episodio : public Video {
private: 
    string titulo;
    int temporada; 

public: 
    Episodio(string titulo = "", int temporada = 0, int id = 0, string nombre = "", string genero = "", int duracion = 0, float calificacion = 0.0);

    string getTitulo();
    int getTemporada();

    void mostrar();

    void setId(int id);
    void setNombre(string nombre);
    void setDuracion(int duracion);
    void setGenero(string genero);
    void setEpisodioTitulo(string titulo);
    void setTemporada(int temporada);
};