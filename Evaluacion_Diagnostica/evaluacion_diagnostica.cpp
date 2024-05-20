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
        simplifica();
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

    static Fraccion suma(Fraccion A, Fraccion B) {
        int numNuevo, denNuevo;

        numNuevo = (A.numerador * B.denominador) + (B.numerador * A.denominador);
        denNuevo = A.denominador * B.denominador;

        Fraccion C(numNuevo, denNuevo);
        return C;
    } 
  
private: 
    void simplifica() {
        int mcdVal = 1;

        if (denominador < 0) {
            numerador *= -1;
            denominador *= -1;
        }

        mcdVal = mcd(numerador, denominador);
        numerador /= mcdVal;
        denominador /= mcdVal;
        
    }
    int mcd(int a, int b) {
        if (a == 0) {
            return b;
        }    
        return mcd(b % a, a);
    }

    int numerador;
    int denominador;
};

void prueba() {
    Fraccion e(1, 2);
}

int main() {
    Fraccion a(10, 5), b;
    
    a.print();
    return 0;
}