#pragma once
#include <iostream>

using namespace std;

class Episodio {
private: 
    string titulo;
    int temporada; 

public: 
    Episodio(string titulo = "", int temporada = 0); 

    string getTitulo();
    int getTemporada();
};