#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main() 
{
    int apenasAtivos = 1;

    fopen(ARQUIVO, "wb"); // cria arquivo binario

    // 1 - Criar um arquivo inicial com 5 alunos 
    Aluno alunos[5] = {
        {1, "MARINA", 10.0, 1},
        {2, "FLAVIO", 11.0, 1},
        {3, "CLEBER", 4.5, 0},
        {4, "MY MELODY", 9.9, 1},
        {5, "JESUS", 6.0, 1}
    };

    for (int i = 0; i < 5; i++) inserirAluno(alunos[i]);

    // 2 - Listar todos os alunos ativos
    listarAlunos(apenasAtivos);

    // 3 - Atualizar a média do aluno com ID 3 para 9.5
    atualizarMediaAluno(3, 9.5);

    // 4 - Apagar (logicamente) o aluno com ID 2 
    deletarAluno(2);

    // 5 - Atualizar um aluno que não existe (ID 99)
    atualizarMediaAluno(99, 9.0);

    printf("\nListando tudo:\n\n");

    apenasAtivos = 0;
    listarAlunos(apenasAtivos);

    exit(0);
    return 0;
}
