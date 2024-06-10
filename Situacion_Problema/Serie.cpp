#include "Serie.h"

Serie::Serie() : numEpisodios(0) {}

void Serie::añadirEpisodio(Episodio episodio) {
    if (numEpisodios < MAX_EPISODIOS) {
        episodios[numEpisodios++] = episodio;
    }
}

Episodio Serie::getEpisodio(int index) {
    if (index >= 0 && index < numEpisodios) {
        return episodios[index];
    }
    return Episodio();
}

int Serie::getNumEpisodios() { 
    return numEpisodios; 
}