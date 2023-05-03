/*Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas sem utilizar variável auxiliar*/
#include <stdio.h>

int mainC(){
  int a;
  int b;

  printf("Digite o valor do primeiro número: ");
  scanf("%d", &a);

  printf("Digite o valor do segundo número: ");
  scanf("%d", &b);

  a = a+b;
  b = a-b;
  a = a-b;

  printf("Os valores após inversão: %d e %d\n", a, b);
}