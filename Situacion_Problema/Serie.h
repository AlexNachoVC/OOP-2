#pragma once
#include "Video.h"
#include "Episodio.h"

using namespace std;


#define MAX_EPISODIOS 100

class Serie {
private:
    Episodio episodios[MAX_EPISODIOS];
    int numEpisodios;

public:
    Serie();

    void añadirEpisodio(Episodio episodio);
    Episodio getEpisodio(int index);

    int getNumEpisodios();
};