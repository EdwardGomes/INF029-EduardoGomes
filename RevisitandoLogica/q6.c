/******************************************************************************
6.Faça um programa que leia a idade de uma pessoa e informe de ela é de maior ou de menor
. O programa deve repetir essa ação até que uma idade negativa seja informada
*******************************************************************************/
#include <stdio.h>

int mainE()
{
   int idade;
   
   printf("Insira sua idade: \n");
   scanf("%d", &idade);
   do {
       printf("Voce eh de maior!\n");
       printf("Insira sua idade: \n");
       scanf("%d", &idade);
   }
   while (idade >=18);
   
   if (idade <=17) {
       printf("voce eh de menor, fim do algoritmo");
   }
   
}