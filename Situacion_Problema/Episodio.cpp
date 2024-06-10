#include "Episodio.h"

Episodio::Episodio(string titulo, int temporada, string id, string nombre, string genero, int duracion, float calificacion)
    : Video(id, nombre, duracion, genero, calificacion), titulo(titulo), temporada(temporada) {}

string Episodio::getTitulo() {
    return titulo; 
}

int Episodio::getTemporada() {
    return temporada; 
}

void Episodio::mostrar() {
    cout << "ID Episodio: " << id << " | "
         << "Nombre Episodio: " << nombre << " | "
         << "Duracion Episodio: " << duracion << " | "
         << "Genero Episodio: " << genero << " | "
         << "Titulo Episodio: " << titulo << " | "
         << "Temporada: " << temporada << " | "
         << "Calificacion Episodio: " << calificacion << endl;
}

void Episodio::setId(string id) {
    this->id = id;
}

void Episodio::setNombre(string nombre) {
    this->nombre = nombre;
}

void Episodio::setDuracion(int duracion) {
    this->duracion = duracion;
}

void Episodio::setGenero(string genero) {
    this->genero = genero;
}

void Episodio::setEpisodioTitulo(string titulo) {
    this->titulo = titulo;
}

void Episodio::setTemporada(int temporada) {
    this->temporada = temporada;
}