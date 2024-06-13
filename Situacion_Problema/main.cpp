#include <iostream>
#include "Video.h"
#include "Pelicula.h"
#include "CSVLoader.h"

#define SERIES_FILE "series.csv"
#define MOVIES_FILE "movies.csv"

using namespace std;

Pelicula *peliculaArray = nullptr;
int dataSizePelicula = 0;

Episodio *episodioArray = nullptr;
int dataSizeSerie = 0;


int main() {
  
    int opcion = 0;
    while (opcion != 6) {
        cout << "\n";
        cout << "1. Cargar archivo de datos\n";
        cout << "2. Mostrar videos con cierta calificacion o genero\n";
        cout << "3. Mostrar episodios de una serie con cierta calificacion\n";
        cout << "4. Mostrar peliculas con cierta calificacion\n";
        cout << "5. Calificar un video\n";
        cout << "6. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                {
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

                    cout << "Archivos de datos cargados de manera exitosa!" << endl;

                    break;
                }

            case 2:
                {
                    if (peliculaArray == nullptr || episodioArray == nullptr) {
                        cout << "\nNo se han cargado los archivos, por favor cargue archivos para poder usar esta opcion" << endl;
                        break;
                    }
                    
                    cout <<  "\nQuiere ver los videos en base a al genero a en base a la calificacion?" << endl << "a) Genero" << endl << "b) Calificacion" << endl;
                    char seleccion;
                    cout << "\nIngresa tu eleccion (la letra correspondiente): ";     
                    cin >> seleccion;         

                    if (tolower(seleccion) == 'a') {
                        cout << "\nOpciones de genero: " << endl << " 1. Drama\n 2. Accion\n 3. Misterio" << endl;
                        int seleccion_genero;  
                        cout << "\nSelecciona el genero (Ingresa el numero correspondiente): ";
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
                        cout << "\nIngresa la calificacion que deseas encontrar: " << endl;
                        float seleccion_calificacion;
                        cin >> seleccion_calificacion;

                        bool found = false;
                        for (int i = 0; i < dataSizePelicula; i++) {
                            if (peliculaArray[i].getCalificacion() == seleccion_calificacion) {
                                peliculaArray[i].mostrar();
                                found = true;
                            }
                        }

                        for (int i = 0; i < dataSizeSerie; i++) {
                            if (episodioArray[i].getCalificacion() == seleccion_calificacion) {
                                episodioArray[i].mostrar();
                                found = true;
                            }
                        }
                        if (!found) {
                            cout << "\nNo se encontraron videos con esa calificacion" << endl;
                        }
                    }
                    break;
                }

            case 3:
                {
                    if (peliculaArray == nullptr || episodioArray == nullptr) {
                        cout << "\nNo se han cargado los archivos, por favor cargue archivos para poder usar esta opcion" << endl;
                        break;
                    }

                    cout << "\nDe que serie le interesa conocer los episodios con cierta calificacion?" << endl;
                    cin.ignore(); // Ignora el carácter de nueva línea que queda en el búfer de entrada después de usar cin. ya que puede causar problemas en la continuacion del codigo el no borrarlo. (Esto lo tuve que investigar por un error, y asi llegue a la solucion. Fuente: https://stackoverflow.com/questions/25475384/when-and-why-do-i-need-to-use-cin-ignore-in-c)
                    string seleccion_serie;
                    getline(cin, seleccion_serie); // Lee una linea entera de entrada del usuario, ya que "cin" solo lee una palabra, por lo que, al estar el nombre de la serie conformado por dos palabras, causaba problemas usar cin.

                    cout << "\nIngresa la calificacion que deseas encontrar: " << endl;
                    float seleccion_calificacion;
                    cin >> seleccion_calificacion;
                    cin.ignore();// Ignora el carácter de nueva línea que queda en el búfer de entrada después de usar cin. ya que puede causar problemas en la continuacion del codigo el no borrarlo 

                    bool found = false;
                    for (int i = 0; i < dataSizeSerie; i++) {
                        if (episodioArray[i].getNombre() == seleccion_serie && episodioArray[i].getCalificacion() == seleccion_calificacion) {
                            episodioArray[i].mostrar();
                            found = true;
                        }
                    }
                    if (!found) {
                        cout << "\nNo se encontraron episodios con esa calificacion" << endl;
                    }

                    break;
                }
                
            case 4:
                {
                    if (peliculaArray == nullptr || episodioArray == nullptr) {
                        cout << "\nNo se han cargado los archivos, por favor cargue archivos para poder usar esta opcion" << endl;
                        break;
                    }
                    
                    cout << "\nCon que calificacion te gustaria que te mostrara peliculas? " << endl;
                    float seleccion_calificacion;
                    cin >> seleccion_calificacion;

                    bool found = false;
                    for (int i = 0; i < dataSizePelicula; i++) {
                        if (peliculaArray[i].getCalificacion() == seleccion_calificacion) {
                            peliculaArray[i].mostrar();
                            found = true;
                        }
                    }
                    if (!found) {
                        cout << "\nNo se encontraron peliculas con esa calificacion" << endl;
                    }

                    break;
                }
                
            case 5:
                {
                    if (peliculaArray == nullptr || episodioArray == nullptr) {
                        cout << "\nNo se han cargado los archivos, por favor cargue archivos para poder usar esta opcion" << endl;
                        break;
                    }
                    
                    cout << "\nDeseas calificar una pelicula o un episodio? (p/e)" << endl;
                    char tipo_video;
                    cin >> tipo_video;
                    cin.ignore();

                    string nombre_video;
                    string titulo_episodio;

                    if (tipo_video == 'p') {
                        cout << "\nIngresa el nombre de la pelicula que deseas calificar: " << endl;
                        getline(cin, nombre_video);
                    } 
                    else if (tipo_video == 'e') {
                        cout << "\nIngresa el nombre de la serie de la cual deseas calificar un episodio: " << endl;
                        getline(cin, nombre_video);

                        cout << "Ingresa el titulo del episodio que deseas calificar: " << endl;
                        getline(cin, titulo_episodio);
                    } 
                    else {
                        cout << "\nTipo de video no valido. Por favor, intenta de nuevo." << endl;
                        break;
                    }

                    cout << "\nIngresa la nueva calificacion: " << endl;
                    float nueva_calificacion;
                    cin >> nueva_calificacion;
                    cin.ignore();

                    if (tipo_video == 'p') {
                        bool found = false;
                        for (int i = 0; i < dataSizePelicula; i++) {
                            if (peliculaArray[i].getNombre() == nombre_video) {
                                peliculaArray[i].setCalificacion(nueva_calificacion);
                                cout << "\nCalificacion actualizada con exito!" << endl;
                                peliculaArray[i].mostrar();
                                found = true;
                                break;
                            }  
                        }
                        if (!found) {
                            cout << "\nNo se encontro la pelicula con el nombre proporcionado." << endl;
                        }
                    }
                    else if (tipo_video == 'e') {
                        bool found = false;
                        for (int i = 0; i < dataSizeSerie; i++) {
                            if (episodioArray[i].getNombre() == nombre_video && episodioArray[i].getTitulo() == titulo_episodio) {
                                episodioArray[i].setCalificacion(nueva_calificacion);
                                cout << "\nCalificacion actualizada con exito!" << endl;
                                episodioArray[i].mostrar();
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            cout << "\nNo se encontro el episodio con el nombre y titulo proporcionados." << endl;
                        }
                    }
                    break;
                }
                
            case 6:
                {
                    cout << "\nSaliendo...\n";
                    break;
                }
                
            default:
                {
                    cout << "\nOpcion no valida. Por favor, intenta de nuevo.\n";
                    break;
                }
        }
    }
}