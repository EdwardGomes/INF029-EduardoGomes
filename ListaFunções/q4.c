//4.Crie um programa que tenha uma função ler3Numeros. Essa função deve ler três números do usuário e retornar os três números. A função main deve imprimir esses três números.//
#include <stdio.h>



int main(){
    int a,b,c;
    void ler3Numeros(int *a, int *b, int *c);
    ler3Numeros(&a,&b,&c);
    printf("Os numeros sao: %d %d %d",a,b,c);
    return 0;
}

void ler3Numeros(int *a, int *b, int *c){
    printf("Digite 3 numeros: ");
    scanf("%d %d %d",a,b,c);
}