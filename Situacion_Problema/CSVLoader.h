#pragma once

#include <string>
#include "Serie.h"
#include "Pelicula.h"
#include "Serie.h"

#define PELICULA_ATTRIB_SIZE 4


bool loadMoviesFromCSV(const std::string& fileName, Pelicula *peliculaArray, unsigned int arraySize);
bool loadSeriesFromCSV(const std::string& fileName, Serie *serieArray, unsigned int arraySize);
int countDataLinesInCSV(const std::string& fileName);

