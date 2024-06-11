#include <iostream>
#include "Video.h"
#include "Pelicula.h"
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


    Episodio *episodioArray = nullptr;
    int dataSizeSerie = 0;

    dataSizeSerie = countDataLinesInCSV(SERIES_FILE);
    if(dataSizeSerie == -1) {
        cerr << "No se pudo cargar el data set de " << SERIES_FILE << "\n";
        return 0;
    }

    cout << "series.csv tiene: " << dataSizeSerie << " entradas\n";
    episodioArray = new(nothrow) Episodio[dataSizeSerie];
    if(episodioArray == nullptr) {
        cerr << "No hubo memoria para el arreglo de " << SERIES_FILE << "\n";
        return 0;
    }

    if(!loadSeriesFromCSV(SERIES_FILE, episodioArray, dataSizeSerie)) {
        cerr << "Error al cargar el data set de " << SERIES_FILE << "\n";
        delete [] episodioArray;
        return 0;
    }

    int opcion = 0;
    while (opcion != 6) {
        cout << "1. Mostrar videos con cierta calificacion o genero\n";
        cout << "2. Mostrar episodios de una serie con cierta calificacion\n";
        cout << "3. Mostrar peliculas con cierta calificacion\n";
        cout << "4. Calificar un video\n";
        cout << "5. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Implementa la funcionalidad para mostrar videos con cierta calificacion o genero
                break;
            case 2:
                // Implementa la funcionalidad para mostrar episodios de una serie con cierta calificacion
                break;
            case 3:
                // Implementa la funcionalidad para mostrar peliculas con cierta calificacion
                break;
            case 4:
                // Implementa la funcionalidad para calificar un video
                break;
            case 5:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion no valida. Por favor, intenta de nuevo.\n";
                break;
        }
    }
}