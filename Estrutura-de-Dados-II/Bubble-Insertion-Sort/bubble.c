#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

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
    printf("sort vector: ");
    printArray(n, ptr);
} 

void magica2(long int n, int *ptr) {
    int *arr = ptr;

    for (long int i = 0; i < n - 1; i++) {
        for (long int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j]; // Questão 6 - Está sendo realizada a troca de um valor ou um ponteiro? 
                /*
                    R: de valores. esta dizendo: troque de lugar o valor armazenado em arr[j] com o valor em arr[j + i]
                */
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("sorted vector: ");
    printArray(n, arr);
}
  
  
int main() // Questão 0 - Verifique se as funções estão funcionando corretamente. Se não, faça a correção.
           //           - Estude o código.
           //           - Altere o valor de n para 1000000. O que pode estar acontecendo com o código?
{ 
    int n = 100; 
    int vet[n]; // Questão 1 - Pq se deve alocar dinamicamente o vetor quando o n > 100 (grande)?

    /*
        srand() = set seed para a funcao rand(), que retorna um numero aleatorio
        time() = retorna tempo atual na maquina e armazena na variavel passada, nesse caso, NULL
    */
    srand(time(NULL)); 

    /*
        popula vetor ao contrario, mas poderiamos usar a funcao rand() no lugar de n - aqui
    */
    for (int i = 0; i < n; i++){
        vet[i] = (n - i); 
    }    
    
    printArray(n, vet);
    
    /*
        clock() retorna na variavel clock_t a quantidade de pulsos de clock desde que o programa foi inicializado até agora
    */
    clock_t begin = clock(); 

    magica(n, vet); // Questão 2 - Qual a diferença entre &vet e vet? 
    /*
        R: depende, vet e &vet nessa mesma sintaxe retornam ambos a mesma coisa, endereco do vetor no indice 0. 
        mas &vet[1] e vet[1] possuem diferencas:  &vet[1] retorna o endereco da variavel e vet[1] o valor armazenado nela.
    */

    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("end time: %f\n\n", time_spent);

    // Questão 3 - O que acontece se a função magica2 for chamada com o argumento &vet ao invés de vet? 
    /*
        R: os dois geram erro pois os dois retornam o endereco do vetor na posicao 0.
    */

    begin = clock();  

    magica2(n, vet);

    end = clock();

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("end time: %f\n\n", time_spent); // Questão 4: Pq o tempo de execução é bem menor na função? 

    return 0; 
} 