#include "Episodio.h"

Episodio::Episodio(std::string titulo, int temporada) : titulo(titulo), temporada(temporada) {}

string Episodio::getTitulo() {
    return titulo; 
}

int Episodio::getTemporada() {
    return temporada; 
}

void Episodio::setTitulo(string titulo) {
    this->titulo = titulo;
}

void Episodio::setTemporada(int temporada) {
    this->temporada = temporada;
}