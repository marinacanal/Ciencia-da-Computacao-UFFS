#include <stdio.h>
#include <string.h>
#include "aluno.h"

int main()
{
    Aluno aluno;
    int opcao, apenasAtivos = 1, id;
    float novaMedia;

    printf("\n.--.                  .                .           .    .   \n");                   
    printf("|   )          o     _|_               |          / \\   |  \n");                     
    printf("|--' .-. .-..  .  .--.|  .--..-.    .-.| .-.     /___\\  | .  . .--. .-. .--. \n");    
    printf("|  \\(.-'(   |  |  `--.|  |  (   )  (   |(.-'    /     \\ | |  | |  |(   )`--. \n");  
    printf("'   ``--'`-`|-' `-`--'`-''   `-'    `-'`-`--' '        ``-`--`-'  `-`-' `--'   \n");
    printf( "        ._.'  \n");
    printf("\nSistema de Registro de Registro de Alunos em Arquivo Binário.\n");

    do {
        printf("\n1. incluir aluno\n");
        printf("2. consultar alunos ativos\n");
        printf("3. alterar média de aluno\n");
        printf("4. excluir aluno\n");
        printf("5. sair\n");

        printf("\n");
        printf("---> escolha: ");
        
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nid: ");
                scanf("%d", &aluno.id);
                getchar(); // limpa o \n

                printf("nome: ");
                fgets(aluno.nome, TAMANHO_NOME, stdin);
                // remove o \n que o fgets guarda no final, se existir
                aluno.nome[strcspn(aluno.nome, "\n")] = '\0';

                printf("média: ");
                scanf("%f", &aluno.media);
                getchar();

                inserirAluno(aluno);
                break;

            case 2:
                listarAlunos(apenasAtivos);
                break;

            case 3:
                printf("\ninforme o id do aluno para consulta: ");
                scanf("%d", &id);
                getchar();

                printf("nova média: ");
                scanf("%f", &novaMedia);
                getchar();
                
                atualizarMediaAluno(id, novaMedia);
                break;

            case 4:
                printf("\ninforme o id do aluno para excluir: ");
                scanf("%d", &id);
                getchar();

                deletarAluno(id);
                break;

            case 7:
                printf("\nsaindo...\n");
                break;

            default:
                printf("opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}