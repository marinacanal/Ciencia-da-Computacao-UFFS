#include "Grafo.h"
#include <iostream>

using namespace std;

const double PI = 3.1416;

Grafo::Grafo(int num_vertices) {
    if(num_vertices <= 0)
        throw(invalid_argument("Erro no construtor Grafo(int): o número de vértices " + to_string(num_vertices) + " eh invalido!"));

    num_vertices_ = num_vertices;
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