/*Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, i;
    int *x, *y, *z;
    printf("Insira o primeiro número: \n");
    scanf("%d", &num1);
    printf("Insira o segundo número: \n");
    scanf("%d", &num2);
  
    x = &num1;
    y = &num2;
    z = &i;

    *z = *x
    *x = *y
    *y = *z
  
    printf("O valor do primeiro numero é: %d\nO valor do segundo número é: %d \n", num1, num2);

    return 0;
}