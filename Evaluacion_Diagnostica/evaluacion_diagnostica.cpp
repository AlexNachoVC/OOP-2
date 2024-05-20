#include <iostream>

class Fraccion {
public:
    Fraccion() {
        numerador = 0;
        denominador = 1;
    }
    Fraccion(int nNumerador, int nDenominador) {
        numerador = nNumerador;
        denominador = nDenominador;
    }
    /*  Fraccion(int numerador, int denominador) {
        this->numerador = numerador;
        this->denominador = denominador;
    }*/
    ~Fraccion() {
    }
  
private: 
    int numerador;
    int denominador;
};

int main() {
    return 0;
}