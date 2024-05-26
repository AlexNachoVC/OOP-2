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
	cout << "Matriz 1:" << endl;
	matriz.print();

	cout << "\n" << "+" << "\n \n";

	// TODO leer matriz2.txt
    if (!matriz2.loadFile("matriz2.txt"))
		return 0;
	cout << "Matriz 2:" << endl;
	matriz2.print();

	// TODO sumar matriz 1 y matriz 2
    MatFrac matrizResultante = MatFrac::sumaMatriz(matriz, matriz2);

	cout << "\n" << "=" << "\n \n";
	cout << "Matriz Resultante:" << endl;
	matrizResultante.print();

	// TODO guardar matriz resultante en matriz3.txt
	if (!matrizResultante.saveToFile("matrizResultante.txt")) {
    	return 1;
	}

	return 0;
}