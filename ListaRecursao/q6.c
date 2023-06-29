/*6) Crie um programa em C, que contenha uma função recursiva que receba dois 
inteiros positivos k e n e calcule kn
. Utilize apenas multiplicações. O programa principal 
deve solicitar ao usuário os valores de k e n e imprimir o resultado da chamada da 
função.*/

#include <stdio.h>
#include <stdlib.h>

int potencia(int k, int n){
    if(n == 0){
        return 1;
    }else{
        return k * potencia(k, n-1);
    }
}

int main(){
    int k, n;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &k);
    printf("Digite outro numero inteiro positivo: ");
    scanf("%d", &n);
    printf("%d elevado a %d eh: %d\n", k, n, potencia(k, n));
    return 0;
}