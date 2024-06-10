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