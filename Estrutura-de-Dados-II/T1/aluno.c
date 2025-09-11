#include <stdio.h>
#include <string.h>
#include "aluno.h"

void inserirAluno(int id, char[TAMANHO_NOME], float media)
{

} 

void listarAlunos()
{
    FILE *filePonteiro;
    char alunosTexto[1000];
    char *atributoAluno;
    Aluno aluno;

    filePonteiro = fopen(ARQUIVO, "r"); // read

    if(!filePonteiro)
        filePonteiro = fopen(ARQUIVO, "w"); // write or create

    while(fread(&aluno, sizeof(Aluno), 1, filePonteiro))
    {
        printf("to aqui");

        if(aluno.ativo == 1)
            printf("%d, %s, %2.f, %d\n", aluno.id, aluno.nome, aluno.media, aluno.ativo);
    }

    fclose(filePonteiro);
}

void atualizarAluno(int id, char[TAMANHO_NOME], float media)

// criar aluno (caminho)
// atualizar aluno (caminho)
// delete aluno (caminho)
// lista aluno (caminho)


