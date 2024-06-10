#pragma once
#include "Video.h"
#include "Episodio.h"

using namespace std;

#define MAX_EPISODIOS 100

class Serie : public Video {
private: 
    Episodio episodios[MAX_EPISODIOS];
    int numEpisodios;

public:
    Serie();
    void añadirEpisodio(const Episodio& episodio);
    Episodio getEpisodio(int index) const;
    int getNumEpisodios() const;
};