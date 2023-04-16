/*Crie um programa que tenha uma função ler3Palavras. Essa função deve ler três palavras do
usuário e retornar as três palavras. A função main deve imprimir essas três palavras.*/
#include <stdio.h>

int main(){
    char a[20],b[20],c[20];
    void ler3Palavras(char *a, char *b, char *c);
    ler3Palavras(a,b,c);
    printf("As palavras sao: %s %s %s",a,b,c);
    return 0;
}

void ler3Palavras(char *a, char *b, char *c){
    printf("Digite 3 palavras: ");
    scanf("%s %s %s",a,b,c);
}