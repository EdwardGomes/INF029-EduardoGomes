//2.Faça um programa que leia a idade de duas pessoas e imprima a soma das idades
#include <stdio.h>

int mainB()
{
    int idade1, idade2, soma;
    
    printf("Coloque a idade da primeira pessoa: \n");
    scanf("%d", &idade1);
    printf("Coloque a idade da segunda pessoa: \n");
    scanf("%d", &idade2);
    soma = idade1+idade2;
    
    printf("A soma das idades é: %d",soma);

}