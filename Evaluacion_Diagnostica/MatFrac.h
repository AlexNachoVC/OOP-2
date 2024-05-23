#pragma once
#include "Fraccion.h"
#include <fstream> 

using namespace std;


#define MAX_REN 100
#define MAX_COL 100

class MatFrac {
public:
    MatFrac() {
        renglones = 0;
        columnas = 0;
    }
    MatFrac(unsigned int nRenglones, unsigned int nColumnas)  {
        if (nRenglones > MAX_REN) {
            cout << "Renglones excede " << MAX_REN << ", limitado." << endl;
        }
        if (nColumnas > MAX_COL) {
            cout << "Columnas excede " << MAX_COL << ", limitado." << endl;
        }
        renglones = nRenglones;
        columnas = nColumnas;
    }
    

    bool loadFile(string fileName) {
        ifstream file;
        int tmpRen = 0, tmpCol = 0;

        file.open(fileName, ios::in);
        if (!file.is_open()) {
            cout << "No se encontro el archivo" << fileName << endl;
            return false;
        }

        if (!(file >> tmpRen)) {
            cout << "No se pudo leer la cantidad de renglones" << endl;
            file.close();
            return false;
        }

        if (!(file >> tmpCol)) {
            cout << "No se pudo leer la cantidad de columnas" << endl;
            file.close();
            return false;
        }

        if (tmpCol > MAX_COL || tmpRen > MAX_REN) {
            cout << "Las dimensiones exceden el máximo de la clase" << endl;
            file.close();
            return false;
        }

        for (unsigned int i = 0; i < tmpCol; i++) {
            for (unsigned int j = 0; j < tmpRen; j++) {
                int a, b;

                if ((!(file >> a)) || (!(file >> b))) {
                    cout << "No se pudieron cargar las fracciones" << endl;
                    columnas = 0;
                    renglones = 0;
                    file.close();
                    return false;
                }

                Fraccion tmp(a, b);
                datos[i][j] = tmp;
            }
        }

        file.close();
        return true;

    }

    void print() {
    }

private:
        unsigned int renglones;
        unsigned int columnas;

    Fraccion datos[MAX_REN][MAX_COL];
};