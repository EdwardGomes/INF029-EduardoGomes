/*5) Crie uma função recursiva que receba um número inteiro positivo N e calcule o 
somatório dos números de 1 a N*/

#include <stdio.h>
#include <stdlib.h>

int somatorio(int n){
    if(n == 1){
        return 1;
    }else{
        return n + somatorio(n-1);
    }
}

int main(){
    int n;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);
    printf("O somatorio de 1 a %d eh: %d\n", n, somatorio(n));
    return 0;
}