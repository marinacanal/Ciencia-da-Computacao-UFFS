#ifndef GRAFO_H

#define GRAFO_H

class Grafo {
    public:
        Grafo(double raio);
        double calcula_area();
        double calcula_perimetro();
        void imprime_area();
        void imprime_perimetro();
    
    private:
        vector<vector<int>> matriz_adjacencia_;
        int num_vertices_;
        int num_arestas_;
}

#endif