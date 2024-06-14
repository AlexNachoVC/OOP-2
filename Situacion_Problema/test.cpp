bool loadVideosFromCSV(const std::string& fileName, Video **&videoArray, unsigned int &arraySize) {
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
        std::stringstream ss(line);
        std::string cell;
        int campo = 0, errores = 0;

        // Leer el tipo de video de la primera columna
        std::getline(ss, cell, ',');
        std::string tipo = cell;

        if(tipo == "P1") {
            Pelicula nPelicula;

            while (std::getline(ss, cell, ',')) {
                if(!cell.length())
                    errores ++;

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

            if(errores || campo != PELICULA_ATTRIB_SIZE) {
                std::cerr << "Error en la linea: " << std::endl << line << std::endl;
                file.close();
                return false;
            }

            if(size < arraySize) {
                videoArray[size] = new Pelicula(nPelicula);
                size ++;
            }
            else {
                std::cerr << "Error, el arreglo es muy pequeño" << std::endl;
                file.close();
                return false;
            }
        }

        else if(tipo == "S1") {
            Episodio nEpisodio;

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
                videoArray[size] = new Episodio(nEpisodio);
                size ++;
            }
            else {
                std::cerr << "Error, el arreglo es muy pequeño" << std::endl;
                file.close();
                return false;
            }
        }
        else {
            std::cerr << "Tipo de video desconocido: " << tipo << std::endl;
            file.close();
            return false;
        }
    }

    file.close();
    return true;
}