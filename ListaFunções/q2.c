/************************************************************************
2.Crie um programa que tenha uma função subtrai e a função main. A função main 
deve ler três valores, enviar para a função subtrai. A função subtrai deve 
realizar a subtração dos três valores (primeiro menos o segundo menos o terceiro)
e retornar o valor. A Função main deve imprimir o resultado da subtração.
************************************************************************/
#include <stdio.h>

int mainSoma(){
    
    int subtrai(int a, int b, int c);
    int a, b, c, resultado;
    
    printf("Insira três valores: \n");
    scanf("%d%d%d", &a, &b, &c);
    resultado = subtrai(a, b, c);
    
    printf("O resultado de %d - %d - %d eh: %d", a, b, c, resultado);
    
    return 1;
}
  
    int subtrai(int a, int b, int c){
     
    int result = a - b - c;
    return result;
     
 }
