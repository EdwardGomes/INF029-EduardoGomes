/******************************************************************************
Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas

*******************************************************************************/
#include <stdio.h>

int main()
{
    int num1, num2, i;
    printf("Insira o primeiro número: \n");
    scanf("%d", &num1);
    printf("Insira o segundo número: \n");
    scanf("%d", &num2);
     i = num1;
     num1 = num2;
     num2 = i;
    printf("O valor do primeiro numero é: %d\nO valor do segundo número é: %d \n", num1, num2);


    return 0;
}
