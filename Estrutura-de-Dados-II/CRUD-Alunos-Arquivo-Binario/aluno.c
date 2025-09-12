#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"

void inserirAluno(Aluno aluno)
{
    Aluno alunoExistente;
    FILE *filePonteiro;
    int alunoJaExiste = 0;  

    filePonteiro = fopen(ARQUIVO, "rb"); // read binary
    if(!filePonteiro)
        filePonteiro = fopen(ARQUIVO, "wb"); // create binary

    while(fread(&alunoExistente, sizeof(Aluno), 1, filePonteiro))
    {
        if(alunoExistente.id == aluno.id)
        {
            printf("\n---> já existe um aluno com esse id!\n\n");
            alunoJaExiste = 1;
            break;
        }
    }

    if(alunoJaExiste == 0)
    {
        filePonteiro = fopen(ARQUIVO, "ab");
        aluno.ativo = 1;
        fwrite(&aluno, sizeof(Aluno), 1, filePonteiro); 
    }

    fclose(filePonteiro); 
} 

void listarAlunos(int apenasAtivos)
{
    FILE *filePonteiro;
    char alunosTexto[1000];
    char *atributoAluno;
    Aluno aluno;

    filePonteiro = fopen(ARQUIVO, "rb"); // read binary

    if(!filePonteiro)
        filePonteiro = fopen(ARQUIVO, "wb"); // create binary

    while(fread(&aluno, sizeof(Aluno), 1, filePonteiro))
    {
        if(aluno.ativo || !apenasAtivos)
        {
            printf("%d, %s, %.2f, %d\n", aluno.id, aluno.nome, aluno.media, aluno.ativo);
        }
    }

    fclose(filePonteiro);
}

void atualizarMediaAluno(int id, float media)
{
    FILE *filePonteiro;
    Aluno aluno;

    filePonteiro = fopen(ARQUIVO, "rb+"); // read binary + update

    if(!filePonteiro)
        filePonteiro = fopen(ARQUIVO, "wb"); // create binary

    while(fread(&aluno, sizeof(Aluno), 1, filePonteiro))
    {
        if(aluno.id == id && aluno.ativo)
        {
            aluno.media = media;
            fseek(filePonteiro, -sizeof(Aluno), SEEK_CUR); // ponteiro volta uma struct
            fwrite(&aluno, sizeof(Aluno), 1, filePonteiro); // reescreve struct e reposiciona ponteiro
            break;
        }
    }

    fclose(filePonteiro); 
} 

void deletarAluno(int id)
{
    FILE *filePonteiro;
    Aluno aluno;

    filePonteiro = fopen(ARQUIVO, "rb+"); // read binary + update

    while(fread(&aluno, sizeof(Aluno), 1, filePonteiro))
    {
        if(aluno.id == id && aluno.ativo)
        {
            aluno.ativo = 0;
            fseek(filePonteiro, -sizeof(Aluno), SEEK_CUR); // ponteiro volta uma struct
            fwrite(&aluno, sizeof(Aluno), 1, filePonteiro); // reescreve struct e reposiciona ponteiro
            break;
        }
    }

    fclose(filePonteiro); 
}