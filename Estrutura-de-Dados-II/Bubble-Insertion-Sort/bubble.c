#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*
    revisando ponteiro:
    * na declaracao da variavel so sinaliza que ela é um ponteiro
    * na chamada da variavel em outros momentos refere-se ao valor no endereco que o ponteiro aponta
    
    int i = 8;
    int *ponteiro; -> declara variavel que aponta para um endereco que armazena um int
    int(*ponteiroArray)[i]; -> declara variavel que aponta para um array de i elementos int
    int arr[5] = {1, 2, 3, 4, 5};

    ponteiro = arr; -> aponta para o endereco do primeiro elemento (na posicao 0) do array
    ponteiro = &i;
    *ponteiro = 10; -> armazena o valor 10 no endereco apontado por ponteiro

    ponteiroArray = &arr; -> aponta para todo o array  
*/

void printArray(int n, int *ptr) {
  for (int i = 0; i < n; ++i) {
    printf("%d  ", ptr[i]);
  }
  printf("\n\n");
}

void swap (int *a, int *b) {
   int temp = *(b);
   *b = *a;
   *a = temp;
};

void magica(int n, int *ptr) { 
    int i, j, t;   
    for (i = 0; i < n; i++) {   
        for (j = i + 1; j < n; j++) {   
            if (*(ptr + j) < *(ptr + i)) {   
                swap((ptr + j), (ptr + i)); // Questão 5 - O parâmetro desta função são valores ou ponteiros? Explique. 
                /*
                    R: sao ponteiros. esta dizendo: troque de lugar o endereco do vetor ptr[j] com o do ptr[i].
                */
            } 
        } 
    }   
    printf("sorted vector: ");
    printArray(n, ptr);
} 

void magica2(long int n, int *ptr) {
    int *arr = ptr;
    int contador = 0;

    for (long int i = 0; i < n - 1; i++) {

        bool listaOrdenada = true;

        for (long int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j]; // Questão 6 - Está sendo realizada a troca de um valor ou um ponteiro? 
                /*
                    R: de valores. esta dizendo: troque de lugar o valor armazenado em arr[j] com o valor em arr[j + i]
                */
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                contador++;
                listaOrdenada = false;
            }
        }

        if(listaOrdenada)
            break;
    }

    printf("sorted vector 2: ");
    printArray(n, arr);

    printf("\n\ncontador: %i", contador);
}
  
int main() // Questão 0 - Verifique se as funções estão funcionando corretamente. Se não, faça a correção.
           //           - Estude o código.
           //           - Altere o valor de n para 1000000. O que pode estar acontecendo com o código?
{
    /*
        R: o programa parece travar. pode ser que a quantidade de operacoes seja muito grande e o programa na verdade so esteja executando o codigo ainda.
    */

    int n = 10000; 
    int *vet = malloc(n * sizeof(int)); // Questão 1 - Pq se deve alocar dinamicamente o vetor quando o n > 100 (grande)?
    /*
        R: porque quando alocamos arrays diretamente, por exemplo, "int vet[n]", estamos utilizando um espaço limitado na memória em forma de
        pilha (de a 1 a 8MB a depender do SO). Isso significa que alocar arrays muito grandes dessa forma pode levar a estouros na pilha, 
        quebrando o programa por falta de memória disponível. Por isso, para variáveis maiores é melhor utilizar a memória em heap, 
        uma região maior e menos limitada de memória disponível. 
    */



    /*
        popula vetor ao contrario, mas poderiamos usar a funcao rand() no lugar de n - aqui
    */
    for (int i = 0; i < n; i++){
        vet[i] = (n - i); 
    }    
    
    printf("sort vector: ");
    printArray(n, vet);
    
    /*
        clock() retorna na variavel clock_t a quantidade de pulsos de clock desde que o programa foi inicializado até agora
    */
    clock_t begin = clock(); 

    //magica(n, vet); // Questão 2 - Qual a diferença entre &vet e vet? 
    /*
        R: &vet aponta para o endereco do vetor inteiro, enquanto vet aponta para o endereco do primeiro elemento do vetor (na posicao 0).
    */

    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("end time: %f\n\n", time_spent);

    // Questão 3 - O que acontece se a função magica2 for chamada com o argumento &vet ao invés de vet? 
    /*
        R: vai dar erro, pois a funcao espera um ponteiro que aponte para um int e nao para um array de int.
    */

    begin = clock();  

    magica2(n, vet);

    end = clock();

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nend time: %f\n\n", time_spent); // Questão 4: Pq o tempo de execução é bem menor na função? 
    /*
        R: 
    */

    return 0; 
} 