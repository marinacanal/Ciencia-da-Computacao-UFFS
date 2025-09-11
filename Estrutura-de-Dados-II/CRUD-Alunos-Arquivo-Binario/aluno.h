#include <stdio.h>

#define TAMANHO_NOME 10
#define ARQUIVO "arquivoAluno.bin"

typedef struct {
    int id;
    char nome[TAMANHO_NOME];
    float media;
    int ativo;
} Aluno;

void inserirAluno(Aluno aluno);
void listarAlunos(int apenasAtivos);
void atualizarMediaAluno(int id, float media);
void deletarAluno(int id);