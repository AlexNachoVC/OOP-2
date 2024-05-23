#include <iostream>
#include "Fraccion.h"
#include "MatFrac.h"

using namespace std;

#define MAX_SIZE 5

int main() {
    Fraccion a(17, 2), b(3,4), c, arreglo[MAX_SIZE];
    
    a.print();
    b.print();

    c = Fraccion::suma(a, b);
    c.print();

    for (int i = 0; i < MAX_SIZE; i++) {
        arreglo[i].print();
    
    }
    return 0;

}