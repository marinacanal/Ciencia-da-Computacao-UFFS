#include "Grafo.h"
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

Grafo::Grafo(int num_vertices)
{
    if (num_vertices <= 0)
        throw(invalid_argument("Erro no construtor Grafo(int): o número de vértices " + to_string(num_vertices) + " eh invalido!"));

    matriz_adjacencia_.resize(num_vertices);

    for (int i = 0; i < num_vertices; i++)
    {
        matriz_adjacencia_[i].resize(num_vertices);
    }

    num_vertices_ = num_vertices;
    num_arestas_ = 0;
}

int Grafo::num_vertices()
{
    return num_vertices_;
}

int Grafo::num_arestas()
{
    return num_arestas_;
}

bool Grafo::tem_aresta(Aresta a)
{
    if (matriz_adjacencia_[a.vertice1][a.vertice2] != 0)
    {
        return true;
    }

    return false;
}

void Grafo::insere_aresta(Aresta a)
{
    if (tem_aresta(a) || a.vertice1 == a.vertice2)
        return;

    matriz_adjacencia_[a.vertice1][a.vertice2] = 1;
    matriz_adjacencia_[a.vertice2][a.vertice1] = 1;

    num_arestas_++;
}

void Grafo::remove_aresta(Aresta a)
{
    if (!tem_aresta(a))
        return;

    matriz_adjacencia_[a.vertice1][a.vertice2] = 0;
    matriz_adjacencia_[a.vertice2][a.vertice1] = 0;

    num_arestas_--;
}

void Grafo::imprimir()
{
    cout << "Grafo: " << endl;

    for (int linha = 0; linha < num_vertices_; linha++)
    {
        cout << linha << ": ";

        for (int coluna = 0; coluna < num_vertices_; coluna++)
        {
            if (matriz_adjacencia_[linha][coluna] == 1)
            {
                cout << coluna << " ";
            }
        }

        cout << endl;
    }

    cout << endl;
}

void Grafo::nao_recebem_mensagem(int origem, int ttl)
{
        cout << origem << " " << ttl << ":";

    vector<int> visitado(num_vertices_, 0);
    vector<int> distancia(num_vertices_, -1);

    queue<int> fila;

    visitado[origem] = 1;
    distancia[origem] = 0;
    fila.push(origem);

    while (!fila.empty())
    {
        int v = fila.front();
        fila.pop();

        if (distancia[v] == ttl)
            continue;

        for (int u = 0; u < num_vertices_; u++)
        {
            if (matriz_adjacencia_[v][u] != 0 && !visitado[u])
            {
                visitado[u] = 1;
                distancia[u] = distancia[v] + 1;
                fila.push(u);
            }
        }
    }

    cout << origem << " " << ttl << ":";

    for (int i = 0; i < num_vertices_; i++)
    {
        if (!visitado[i])
            cout << " " << i;
    }

    cout << endl;
}