#include <iostream>
#include "Fraccion.h"

using namespace std;

int main() {
    Fraccion a(17, 2), b(3,4), c, arreglo[5];
    
    a.print();
    b.print();

    c = Fraccion::suma(a, b);
    c.print();

    return 0;
}