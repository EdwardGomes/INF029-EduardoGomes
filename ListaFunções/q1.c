/******************************************************************************
1.Crie um programa que tenha uma função soma e a função main. A função main deve
ler dois valores, enviar para a função soma. A função soma deve realizar a 
soma e retornar o valor. A Função main deve imprimir o resultado da soma.
************************************************************************/
#include <stdio.h>

int main()
{
    int soma(int a, int b);
    int a, b;
    
    printf("Digite dois valores: \n");
    scanf("%d%d", &a, &b);
    int resultado = soma(a, b);

    printf("A soma entre esses numeros eh %d\n", resultado);
    return 1;
}

int soma(int a, int b)
{
    int resultado = a + b;
    return resultado;
}