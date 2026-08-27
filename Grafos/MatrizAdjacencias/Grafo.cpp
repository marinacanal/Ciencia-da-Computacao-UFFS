#include "Grafo.h"
#include <iostream>
#include <algorithm>

using namespace std;

Grafo::Grafo(int num_vertices) {
    if(num_vertices <= 0)
        throw(invalid_argument("Erro no construtor Grafo(int): o número de vértices " + to_string(num_vertices) + " eh invalido!"));

    matriz_adjacencia_.resize(num_vertices);

    for(int i = 0; i < num_vertices;  i++) {
        matriz_adjacencia_[i].resize(num_vertices);
    }

    num_vertices_ = num_vertices;
    num_arestas_ = 0; 
}

int Grafo::num_vertices() {
    return num_vertices_;
}

int Grafo::num_arestas() {
    return num_arestas_;
}

bool Grafo::tem_aresta(Aresta a) {
    if(matriz_adjacencia_[a.vertice1][a.vertice2] != 0) {
        return true;
    }

    return false;
}

void Grafo::insere_aresta(Aresta a) {
    if (tem_aresta(a) || a.vertice1 == a.vertice2)
        return;

    matriz_adjacencia_[a.vertice1][a.vertice2] = 1;
    matriz_adjacencia_[a.vertice2][a.vertice1] = 1;

    num_arestas_++;
}

void Grafo::remove_aresta(Aresta a) {
    if(!tem_aresta(a))
        return;

    matriz_adjacencia_[a.vertice1][a.vertice2] = 0;
    matriz_adjacencia_[a.vertice2][a.vertice1] = 0;

    num_arestas_--;
}

void Grafo::imprimir() {
    cout << "Grafo: " << endl;

    for (int linha = 0; linha < num_vertices_; linha++) {
        cout << linha << ": ";

        for (int coluna = 0; coluna < num_vertices_; coluna++) {
            if(matriz_adjacencia_[linha][coluna] == 1) 
            {
                cout << coluna << " ";
            }    
        }

        cout << endl;
    }

    cout << endl;
}

bool Grafo::eh_passeio(vector<int> &seq_vertices) {
    for(int i = 0; i < (int)seq_vertices.size(); i++) {
        if(!tem_aresta(Aresta(seq_vertices[i], seq_vertices[i + 1]))) {
            return false;
        }
    }

    return true;
}

bool Grafo::eh_caminho(vector<int> &seq_vertices) {
    vector<int> seq_vertices_ordenado = seq_vertices;
    sort(seq_vertices_ordenado.begin(), seq_vertices_ordenado.end());

    for(int i = 1; i < (int)seq_vertices.size(); i++) {
        if(seq_vertices[i] == seq_vertices[i - 1]) {
            return false;
        }
    }

    return eh_passeio(seq_vertices);
}

int Grafo::grau(int vertice) {
    int grau = 0;

    for(int i = 0; i < num_vertices_; i++) {
        if (matriz_adjacencia_[i][vertice] == 1)
            grau++;
    }

    return grau;
 }

int Grafo::grau_minimo() {
    int menor_grau = num_vertices_ - 1;

    for(int i = 0; i < num_vertices_; i++){
        int grau_vertice = grau(i);

        if(grau_vertice < menor_grau)
            menor_grau = grau_vertice;
    } 

    return menor_grau;
}

bool Grafo::existe_caminho(int v1, int v2, int marcado[], int nivel) {
    for(int n = 0; n < nivel; n++) {
        cout << "--";
    }

    cout << "caminho(" << v1 << ", " << v2 << ")" << endl;

    if (v1 == v2) {    
        return true;
    }
        
    marcado[v1] = 1;

    for (int i = 0; i < num_vertices_; i++) { 

        if (tem_aresta(Aresta(v1, i)) && marcado[i] == 0) {

            if (existe_caminho(i, v2, marcado, nivel + 1)) 
                return true;

        }         
    }

    return false;
}