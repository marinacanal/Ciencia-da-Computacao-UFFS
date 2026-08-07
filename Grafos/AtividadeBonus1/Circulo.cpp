#include <iostream>
#include "Circulo.h"

const double PI = 3.1416;

Circulo::Circulo(double raio) {
    if(raio <= 0)
        throw(invalid_argument("Erro no construtor Circulo(double): o raio " + to_string(raio) + " eh invalido!"));

    raio_ = raio;
}

double Circulo::calcula_area() {
    return PI * raio_ * raio_;
}

void Circulo::imprime_area() {
    cout << "Área: " << calcula_area() << endl;
}

double Circulo::calcula_perimetro() {
    return PI * raio_ * 2;
}

void Circulo::imprime_perimetro() {
    cout << "Perímetro: " << calcula_perimetro() << endl;
}