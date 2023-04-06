/******************************************************************************
8.Faça um programa que calcula o fatorial de um número
*******************************************************************************/
#include <stdio.h>

int mainQ()
{
    int fatorial;
    int resposta=1;
    printf("Insura um numero: \n");
    scanf("%d", &fatorial);
    
    for ( ; fatorial >= 1; --fatorial){
        resposta *= fatorial;
    }
    printf("O fatorial deste numero eh: %d", resposta);
    return 0;
}
