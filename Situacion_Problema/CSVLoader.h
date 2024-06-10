#pragma once

#include <string>
#include "Serie.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"

#define PELICULA_ATTRIB_SIZE 5
#define SERIE_ATTRIB_SIZE 7


bool loadMoviesFromCSV(const std::string& fileName, Pelicula *peliculaArray, unsigned int arraySize);
bool loadSeriesFromCSV(const std::string& fileName, Serie *serieArray, unsigned int arraySize);
int countDataLinesInCSV(const std::string& fileName);

