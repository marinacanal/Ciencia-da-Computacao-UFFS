#include <iostream>
#include "Grafo.h"

using namespace std;

int main()
{
    int N, C;
    cin >> N >> C;

    Grafo g(N);

    for (int i = 0; i < C; i++)
    {
        int x, y;
        cin >> x >> y;

        Aresta a(x, y);

        g.insere_aresta(a);
    }

    int O;
    cin >> O;
    cout << O;
    
    for (int i = 0; i < O; i++)
    {
        int origem, ttl;
        cin >> origem >> ttl;

        g.nao_recebem_mensagem(origem, ttl);
    }

    return 0;
}