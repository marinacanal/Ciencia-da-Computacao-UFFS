#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

//Questões para serem entregues. 

//1- Rode o código e verifique se está funcionando corretamente a partir do debug. 

//2- Crie uma variável para indicar quantas operações de comparação foram executadas pelo algortimo de bublle e pelo Insertion. Para a mesma entrada de 10000 elementos quantas comparações foram realizadas? 
/*
    R: 49995000 em ambos os algoritmos de ordenacao, bubble e insertion.
*/

//3- Quais são as diferenças entre os métodos bubble e insertion sort? 

//4- Existe algum caso em que o buble é melhor que o sort em número de comparações?

//5 - Compute o tempo para fazer o ordenamento de um mesmo vetor randômico com 100000 valores usando o bubble e o insertion. 

void sort(int n, int* ptr){
    int i,j, min, t;
    int contador = 0;

    printf("sort vector: \n");
    printf("%d ", ptr[0]);

    for (i = 1; i < n; i++) { 
        printf("%d ", ptr[i]); 

        min = ptr[i];

        for (j = i; j >= 1 && min < ptr[j - 1]; j--){
            ptr[j] = ptr[j - 1];  
            contador++;             
        }  

        ptr[j] = min;     
    }

    printf("\n\nsorted vector: \n");

    for (int i = 0; i < n; i++){
        printf("%d ", ptr[i]);
    }

    printf("\n\ncontador: %i", contador);
}


int main() 
{ 
    // vector size
    long int n = 10000; 
    // memory allocation

    int *vet = (int*)malloc(n * sizeof(int));
    srand(time(NULL));
   
    // for (int i = 0; i < n; i++){
    //     vet[i] = (rand() % 100);
    // }    

    for (int i = 0; i < n; i++){
        vet[i] = (n - i); 
    }   
    
    clock_t begin = clock();  

    sort(n, vet); 

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nend time: %f\n", time_spent);
    return 0; 
} 