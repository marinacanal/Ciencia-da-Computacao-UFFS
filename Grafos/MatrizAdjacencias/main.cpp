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
        
        cout << "Tem aresta (1, 3): " << grafo.tem_aresta(Aresta(1, 3)) << endl;
        cout << "Tem aresta (1, 2): " << grafo.tem_aresta(Aresta(1, 2)) << endl;
        grafo.imprimir();

        grafo.insere_aresta(Aresta(1, 3));
        cout << "Tem aresta (1, 3): " << grafo.tem_aresta(Aresta(1, 3)) << endl;
        cout << "Tem aresta (1, 2): " << grafo.tem_aresta(Aresta(1, 2)) << endl;
        grafo.imprimir();

        grafo.remove_aresta(Aresta(1, 3));
        grafo.remove_aresta(Aresta(1, 2));
        cout << "Tem aresta (1, 2): " << grafo.tem_aresta(Aresta(1, 2)) << endl;
        grafo.imprimir();
    }
    catch(const exception &e) {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}