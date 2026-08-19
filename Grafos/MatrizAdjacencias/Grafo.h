#ifndef GRAFO_H

#define GRAFO_H

#include <vector>

class Grafo {
    public:
        Grafo(int num_vertices);

        int num_vertices();
        int num_arestas();
    
    private:
        vector<vector<int>> matriz_adjacencia_;
        int num_vertices_;
        int num_arestas_;
};

#endif