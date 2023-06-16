/*1) Faça uma função recursiva que calcule e retorne o fatorial de um número inteiro N.*/

#include <stdio.h>
#include <stdio.h>

int fatorial(int n);

int main(){

    fatorial(10);
    printf("%d", fatorial(10));
}

int fatorial(int n){
    if(n == 0){
        return 1;
    }else{
        return n * fatorial(n-1);
    }
}