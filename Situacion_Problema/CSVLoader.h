#pragma once

#include <string>
#include "Pelicula.h"
#include "Episodio.h"

#define PELICULA_ATTRIB_SIZE 5
#define SERIE_ATTRIB_SIZE 7

bool loadVideosFromCSV(const std::string& fileName, Video **&videoArray, unsigned int &arraySize); // modificamos la implementacion, para solo hacer un array de videos, y no uno de cada tipo

int countDataLinesInCSV(const std::string& fileName);

