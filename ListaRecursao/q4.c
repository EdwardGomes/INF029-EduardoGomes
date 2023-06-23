/*4) Faça uma função recursiva que permita somar os elementos de um vetor de 
inteiros.*/

#include <stdio.h>
#include <stdlib.h>

int soma(int *vetor, int tam);

int main(){
    int vetor[5] = {1, 2, 3, 4, 5};
    int tam = 5;
    int resultado = soma(vetor, tam);
    printf("Resultado: %d\n", resultado);
    return 0;
}

int soma(int *vetor, int tam){
    if(tam == 1){
        return vetor[tam - 1];
    }else{
        return vetor[tam - 1] + soma(vetor, tam - 1);
    }
}