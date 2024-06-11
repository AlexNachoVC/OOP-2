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
                {
                    cout <<  "Quiere ver los videos en base a al genero a en base a la calificacion?" << endl << "a) Genero" << endl << "b) Calificacion" << endl;
                    char seleccion;
                    cout << "Ingresa tu eleccion: ";     
                    cin >> seleccion;         

                    if (tolower(seleccion) == 'a') {
                        cout << "Opciones de genero: " << endl << " 1. Drama\n 2. Accion\n 3. Misterio" << endl;
                        int seleccion_genero;  
                        cout << "Selecciona el genero: ";
                        cin >> seleccion_genero; 

                        string genero;
                        switch (seleccion_genero) {
                            case 1:
                                genero = "Drama";
                                break;
                            case 2:
                                genero = "Accion";
                                break;
                            case 3:
                                genero = "Misterio";
                                break;
                            default:
                                cout << "Opcion no valida." << endl;
                                break;
                        }

                        for (int i = 0; i < dataSizePelicula; i++) {
                            if (peliculaArray[i].getGenero() == genero) {
                                peliculaArray[i].mostrar();
                            }
                        }

                        for (int i = 0; i < dataSizeSerie; i++) {
                            if (episodioArray[i].getGenero() == genero) {
                                episodioArray[i].mostrar();
                            }
                        }
                    }

                    else if (tolower(seleccion) == 'b') {
                        cout << "Ingresa la calificacion que deseas encontrar: " << endl;
                        float seleccion_calificacion;
                        cin >> seleccion_calificacion;

                        for (int i = 0; i < dataSizePelicula; i++) {
                            if (peliculaArray[i].getCalificacion() == seleccion_calificacion) {
                                peliculaArray[i].mostrar();
                            }
                        }

                        for (int i = 0; i < dataSizeSerie; i++) {
                            if (episodioArray[i].getCalificacion() == seleccion_calificacion) {
                                episodioArray[i].mostrar();
                            }
                        }
                    }
                    break;
                }
            case 2:
                {
                    cout << "De que serie le interesa conocer los episodios con cierta calificacion?" << endl;
                    cin.ignore(); // Ignora el carácter de nueva línea que queda en el búfer de entrada después de usar cin. ya que puede causar problemas en la continuacion del codigo el no borrarlo 
                    string seleccion_serie;
                    getline(cin, seleccion_serie); // Lee una linea entera de entrada del usuario, ya que "cin" solo lee una palabra, por lo que, al estar el nombre de la serie conformado por dos palabras, causaba problemas usar cin.

                    cout << "Ingresa la calificacion que deseas encontrar: " << endl;
                    float seleccion_calificacion;
                    cin >> seleccion_calificacion;
                    cin.ignore();// Ignora el carácter de nueva línea que queda en el búfer de entrada después de usar cin. ya que puede causar problemas en la continuacion del codigo el no borrarlo 

                    for (int i = 0; i < dataSizeSerie; i++) {
                        if (episodioArray[i].getNombre() == seleccion_serie && episodioArray[i].getCalificacion() == seleccion_calificacion) {
                            episodioArray[i].mostrar();
                        }
                    }
                    break;
                }
            case 3:
                {
                    cout << "Con que calificacion te gustaria que te mostrara peliculas? " << endl;
                    float seleccion_calificacion;
                    cin >> seleccion_calificacion;

                    for (int i = 0; i < dataSizePelicula; i++) {
                        if (peliculaArray[i].getCalificacion() == seleccion_calificacion) {
                            peliculaArray[i].mostrar();
                        }
                    }

                }
                break;
            case 4:
                
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