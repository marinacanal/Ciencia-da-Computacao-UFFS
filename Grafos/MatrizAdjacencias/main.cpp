/* 
Desenvolvido por: Marina Canal
Matéria: Grafos
UFFS - Chapecó 
*/

#include "Grafo.h"
#include <iostream>

using namespace std;

int main() {
    try {
        Grafo grafo(6);
        
        // cout << "Tem aresta (1, 3): " << grafo.tem_aresta(Aresta(1, 3)) << endl;
        // cout << "Tem aresta (1, 2): " << grafo.tem_aresta(Aresta(1, 2)) << endl;
        // grafo.imprimir();

        // grafo.insere_aresta(Aresta(1, 3));
        // cout << "Tem aresta (1, 3): " << grafo.tem_aresta(Aresta(1, 3)) << endl;
        // cout << "Tem aresta (1, 2): " << grafo.tem_aresta(Aresta(1, 2)) << endl;
        // grafo.imprimir();

        // grafo.remove_aresta(Aresta(1, 3));
        // grafo.remove_aresta(Aresta(1, 2));
        // cout << "Tem aresta (1, 2): " << grafo.tem_aresta(Aresta(1, 2)) << endl;
        // grafo.imprimir();

        grafo.insere_aresta(Aresta(0, 1));
        grafo.insere_aresta(Aresta(0, 2));
        grafo.insere_aresta(Aresta(0, 5));
        grafo.insere_aresta(Aresta(2, 3));
        grafo.insere_aresta(Aresta(2, 4));
        grafo.insere_aresta(Aresta(2, 5));
        grafo.insere_aresta(Aresta(3, 4));
        grafo.insere_aresta(Aresta(3, 5));

        grafo.imprimir();

        int marcado[grafo.num_vertices()] = {0};
        grafo.existe_caminho(0, 4, marcado, 0);        
    }
    catch(const exception &e) {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}