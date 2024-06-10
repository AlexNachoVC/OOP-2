#include <iostream>
#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include "CSVLoader.h"

#define SERIES_FILE "series.csv"
#define MOVIES_FILE "movies.csv"

using namespace std;

int main() {
    Pelicula *peliculaArray = nullptr;
    int dataSizePelicula = 0;

    dataSizePelicula = countDataLinesInCSV(MOVIES_FILE);
    if(dataSizePelicula == -1) {
        cerr << "No se pudo cargar el data set de " << MOVIES_FILE << "\n";
        return 0;
    }

    cout << "movies.csv tiene: " << dataSizePelicula << " entradas\n";
    peliculaArray = new(nothrow) Pelicula[dataSizePelicula];
    if(peliculaArray == nullptr) {
        cerr << "No hubo memoria para el arreglo de " << MOVIES_FILE << "\n";
        return 0;
    }

    if(!loadMoviesFromCSV(MOVIES_FILE, peliculaArray, dataSizePelicula)) {
        cerr << "Error al cargar el data set de " << MOVIES_FILE << "\n";
        delete [] peliculaArray;
        return 0;
    }


    Serie *serieArray = nullptr;
    int dataSizeSerie = 0;

    dataSizeSerie = countDataLinesInCSV(SERIES_FILE);
    if(dataSizeSerie == -1) {
        cerr << "No se pudo cargar el data set de " << SERIES_FILE << "\n";
        return 0;
    }

    cout << "series.csv tiene: " << dataSizeSerie << " entradas\n";
    serieArray = new(nothrow) Serie[dataSizeSerie];
    if(serieArray == nullptr) {
        cerr << "No hubo memoria para el arreglo de " << MOVIES_FILE << "\n";
        return 0;
    }

    if(!loadSeriesFromCSV(SERIES_FILE, serieArray, dataSizeSerie)) {
        cerr << "Error al cargar el data set de " << MOVIES_FILE << "\n";
        delete [] serieArray;
        return 0;
    }
}