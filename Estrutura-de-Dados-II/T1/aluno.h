#include <stdio.h>

#define TAMANHO_NOME 10
#define ARQUIVO "arquivoAluno.txt"

typedef struct {
    int id;
    char nome[TAMANHO_NOME];
    float media;
    int ativo;
} Aluno;

void inserirAluno(int id, char[TAMANHO_NOME], float media);
void listarAlunos();
void atualizarAluno(int id, char[TAMANHO_NOME], float media);
void deletarAluno(int id);