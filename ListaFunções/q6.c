/*Crie um programa que tenha uma função ler3Letras. Essa função deve ler três letras do usuário
e retornar as três letras. A função main deve imprimir essas três letras.*/
#include <stdio.h>

int main(){
    char a,b,c;
    void ler3Letras(char *a, char *b, char *c);
    ler3Letras(&a,&b,&c);
    printf("As letras sao: %c %c %c",a,b,c);
    return 0;
}

void ler3Letras(char *a, char *b, char *c){
    printf("Digite 3 letras: ");
    scanf("%c %c %c",a,b,c);
}