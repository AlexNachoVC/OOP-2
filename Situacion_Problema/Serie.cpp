#include "Serie.h"

Serie::Serie() : numEpisodios(0) {}

void Serie::añadirEpisodio(const Episodio& episodio) {
    if (numEpisodios < MAX_EPISODIOS) {
        episodios[numEpisodios] = episodio;
        numEpisodios++;
    }
}

Episodio Serie::getEpisodio(int index) const {
    if (index >= 0 && index < numEpisodios) {
        return episodios[index];
    }

    return Episodio();
}

int Serie::getNumEpisodios() const {
    return numEpisodios;
}

void Serie::setId(int id) {
    this->id = id;
}

void Serie::setNombre(string nombre) {
    this->nombre = nombre;
}

void Serie::setDuracion(int duracion) {
    this->duracion = duracion;
}

void Serie::setGenero(string genero) {
    this->genero = genero;
}

void Serie::setEpisodioTitulo(string titulo) {
    this->episodio.setTitulo(titulo);
}

void Serie::setTemporada(int temporada) {
    this->episodio.setTemporada(temporada);
}