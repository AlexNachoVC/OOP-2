/*
 * Ejemplos secuenciales de uso de memoria
 * por Artemio Urbina
 *
 * Ejemplo 4 de uso de memoria dinámica
 *
 * Este ejemplo tiene la intención de 
 * mostrar como new puede reservar
 * memoria ne una parte del programa
 * y podemos liberarla en otro lugar.
 */
 #include <iostream>

using namespace std;

class Persona {
public:
    Persona() { cout << "Persona creada\n"; }
    ~Persona() { cout << "Persona destruida\n"; }
};

Persona* crearPersona() {
    Persona* ptr = nullptr;

    ptr = new(nothrow) Persona();
    cout << "crear persona: " << ptr << endl;

    if(!ptr) {
        cout << "Not enough memory\n";
    }
    return ptr;
}

int main() {
    Persona* ptr = nullptr;

    ptr = crearPersona();
        cout << "main: " << ptr << endl;

    if(ptr) {
        delete ptr;
        ptr = nullptr;
    }

    return 0;
}
