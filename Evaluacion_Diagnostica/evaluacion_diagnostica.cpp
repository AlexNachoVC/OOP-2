#include <iostream>
#include "Fraccion.h"
#include "MatFrac.h"

using namespace std;

#define MAX_SIZE 5

int main() {
    MatFrac matriz;
    MatFrac matriz2;

	if (!matriz.loadFile("matriz1.txt"))
		return 0;
	//matriz.print();

	// TODO leer matriz2.txt
    if (!matriz2.loadFile("matriz2.txt"))
		return 0;
	//matriz2.print();

	// TODO sumar matriz 1 y matriz 2
    MatFrac matrizResultante = MatFrac::sumaMatriz(matriz, matriz2);
	matrizResultante.print();
	// TODO guardar matriz resultante en matriz3.txt
	return 0;
}