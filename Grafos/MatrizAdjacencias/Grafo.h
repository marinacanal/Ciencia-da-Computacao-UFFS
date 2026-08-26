#ifndef GRAFO_H

#define GRAFO_H

#include "Aresta.h"
#include <vector>

/*
    não é boa prática usar "using namespace std" aqui, 
    pois pode ser que quando eu queira importar esse arquivo eu não queira levar levar o std junto
*/ 

class Grafo {
    public:
        Grafo(int num_vertices);

        int num_vertices();
        int num_arestas();
        bool tem_aresta(Aresta a);
        void insere_aresta(Aresta a);
        void remove_aresta(Aresta a);
        void imprimir();

        bool eh_passeio(std::vector<int> &seq_vertices);
        bool eh_caminho(std::vector<int> &seq_vertices);
        
        int grau(int vertice);
        int grau_minimo();
    
    private:
        /*
            quando eu uso vector, nao preciso liberar a memoria utilizada para alocar o objeto, pois isso ja eh feito automaticamente
        */
        std::vector<std::vector<int>> matriz_adjacencia_;
        int num_vertices_;
        int num_arestas_;
};

#endif /* GRAFO_H */