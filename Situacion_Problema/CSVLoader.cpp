#include "CSVLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool loadMoviesFromCSV(const std::string& fileName, Pelicula *peliculaArray, unsigned int arraySize) {
    std::ifstream        file(fileName);
    std::string          line;
    unsigned int         size = 0;

    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo: " << fileName << std::endl;
        return false;
    }

    // skip header
    if(!std::getline(file, line)) {
        std::cerr << "El archivo no tiene header" << std::endl;
        file.close();
        return false;
    }

    std::cout << "Cargando archivo: " << fileName << std::endl;

    while (std::getline(file, line)) {
        Pelicula        nPelicula;
        std::stringstream    ss(line);
        std::string          cell;
        int             campo = 0, errores = 0;

        while (std::getline(ss, cell, ',')) {
            if(!cell.length())
                errores ++;
            
            // ir coma por coma, esta version no valida que sean enteros o floats
            // por simplicidad
            switch(campo) {
                case 0:
                    nPelicula.setId(cell);
                    break;
                case 1:
                    nPelicula.setNombre(cell);
                    break;
                case 2:
                    nPelicula.setDuracion(std::stoi(cell));
                    break;
                case 3:
                    nPelicula.setGenero(cell);
                    break;
                case 4:
                    nPelicula.setCalificacion(std::stof(cell));
                    break;

                default:
                    errores ++;
                    break;
            }
            campo ++;
        }

        // Comparar si son X campos, aqui depende de cuantas 
        // entradas tiene cada clase, el X esta definido en el h
        // como PELICULA_ATTRIB_SIZE
        if(errores || campo != PELICULA_ATTRIB_SIZE) {
            std::cerr << "Error en la linea: " << std::endl << line << std::endl;
            file.close();
            return false;
        }

        if(size < arraySize) {
            peliculaArray[size] = nPelicula;
            size ++;
        }
        else {
            std::cerr << "Error, el arreglo es muy pequeño" << std::endl;
            file.close();
            return false;
        }
    }

    file.close();
    
    return true;
}

bool loadSeriesFromCSV(const std::string& fileName, Episodio *episodioArray, unsigned int arraySize) {
    std::ifstream file(fileName);
    std::string line;
    unsigned int size = 0;

    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo: " << fileName << std::endl;
        return false;
    }

    // skip header
    if(!std::getline(file, line)) {
        std::cerr << "El archivo no tiene header" << std::endl;
        file.close();
        return false;
    }

    std::cout << "Cargando archivo: " << fileName << std::endl;

    while (std::getline(file, line) && size < arraySize) {
        Episodio nEpisodio;
        std::stringstream ss(line);
        std::string cell;
        int campo = 0, errores = 0;

        while (std::getline(ss, cell, ',')) {
            if(!cell.length())
                errores ++;

            switch(campo) {
                case 0: 
                    nEpisodio.setId(cell); 
                    break;
                case 1: 
                    nEpisodio.setNombre(cell); 
                    break;
                case 2: 
                    nEpisodio.setDuracion(std::stof(cell)); 
                    break;
                case 3: 
                    nEpisodio.setGenero(cell); 
                    break;
                case 4: 
                    nEpisodio.setEpisodioTitulo(cell); 
                    break;
                case 5: 
                    nEpisodio.setTemporada(std::stoi(cell)); 
                    break;
                case 6: 
                    nEpisodio.setCalificacion(std::stof(cell));
                    break;
                default: errores++; break;
            }
            campo++;
        }

        if(errores || campo != SERIE_ATTRIB_SIZE) {
            std::cerr << "Error en la linea: " << std::endl << line << std::endl;
            file.close();
            return false;
        }

        if(size < arraySize) {
            episodioArray[size] = nEpisodio;
            size ++;
        }
        else {
            std::cerr << "Error, el arreglo es muy pequeño" << std::endl;
            file.close();
            return false;
        }
    }

    file.close();
    return true;
}

int countDataLinesInCSV(const string& fileName) {
    ifstream    file(fileName);
    int         lineCount = 0;
    string      line;

    // Contar la cantidad de líneas en el archivo csv
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << fileName << endl;
        return -1;
    }

    // skip header
    if(!getline(file, line)) {
        cerr << "El archivo no tiene header" << endl;
        file.close();
        return -1;
    }

    // Contar lineas 
    while(getline(file, line)) {
        lineCount++;    
    }

    file.close();
    return(lineCount);
}