#include "NumComplejo.h"
#include <iostream>

using namespace std;

NumComplejo::NumComplejo(int n_a, int n_b) {
    a = n_a;
    b = n_b;
}

NumComplejo NumComplejo::sumaComplejo(NumComplejo uno, NumComplejo dos) {
    int resultadoA = uno.a + dos.a;
    int resultadoB = uno.b + dos.b;

    return NumComplejo(resultadoA, resultadoB);
}

NumComplejo NumComplejo::restaComplejo(NumComplejo uno, NumComplejo dos) {
    int resultadoA = uno.a - dos.a;
    int resultadoB = uno.b - dos.b;

    return NumComplejo(resultadoA, resultadoB);
}

void NumComplejo::imprimir() {

    cout << a << "+" << b << "i" << endl; 
}