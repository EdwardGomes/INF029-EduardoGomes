/*7) Crie um programa em C que receba um vetor de números reais com 100 elementos. 
Escreva uma função recursiva que inverta ordem dos elementos presentes no vetor.*/

#include <stdio.h>
#include <stdlib.h>

void inverteVetor(float *vetor, int tamanho){
    if(tamanho == 0){
        return;
    }else{
        float aux = vetor[tamanho-1];
        vetor[tamanho-1] = vetor[0];
        vetor[0] = aux;
        inverteVetor(vetor+1, tamanho-2);
    }
}

int main(){
    float vetor[100];
    for(int i = 0; i < 100; i++){
        vetor[i] = i;
    }
    inverteVetor(vetor, 100);
    for(int i = 0; i < 100; i++){
        printf("%.2f ", vetor[i]);
    }
    printf("\n");
    return 0;
}