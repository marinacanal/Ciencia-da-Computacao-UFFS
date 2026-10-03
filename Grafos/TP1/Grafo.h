#ifndef GRAFO_H

#define GRAFO_H

#include "Aresta.h"
#include <vector>

class Grafo {
    public:
        Grafo(int num_vertices);

        int num_vertices();
        int num_arestas();
        bool tem_aresta(Aresta a);
        void insere_aresta(Aresta a);
        void remove_aresta(Aresta a);
        void imprimir();

        void busca_largura(int v);
    
    private:
        std::vector<std::vector<int>> matriz_adjacencia_;
        int num_vertices_;
        int num_arestas_;
};

#endif /* GRAFO_H */