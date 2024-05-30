#pragma once

class NumComplejo {
public:
    int a, b;
    NumComplejo() {
        a = 0;
        b = 0;
    } 
    NumComplejo(int n_a, int n_b);

    static NumComplejo sumaComplejo(NumComplejo uno, NumComplejo dos);
    static NumComplejo restaComplejo(NumComplejo uno, NumComplejo dos);
    void imprimir();
};