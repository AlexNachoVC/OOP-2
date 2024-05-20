#include <iostream>

using namespace std;
class Fraccion {
public:
    Fraccion() {
        numerador = 0;
        denominador = 1;
    }
    Fraccion(int nNumerador, int nDenominador) {
        numerador = nNumerador;
        if (nDenominador != 0) {
            denominador = nDenominador;
        } else {
            cout << "El denominador no puede ser 0, se asigno 1";
            denominador = 1;
        }
    }
    /*  Fraccion(int numerador, int denominador) {
        this->numerador = numerador;
        this->denominador = denominador;
    }*/
   
    ~Fraccion() {
    }

    

    void print() {
        cout << numerador;
        if (denominador != 1) {
           cout << "/" << denominador << endl;
        } 
    }
  
private: 
    void simplifica() {
        int mcdVal = 1;

        mcdVal = mcd(numerador, denominador);
        if (denominador < 0) {
            numerador *= -1;
            denominador *= -1;
        }

        
    }
    int mcd(int a, int b) {
        if (a == 0) {
            return b;
        return mcd(b % a, a);
    }

    }
    int numerador;
    int denominador;
};

void prueba() {
    Fraccion e(1, 2);
}

int main() {
    Fraccion a(-7, -6), b;
    
    a.print();
    return 0;
}