//Faça um programa que tenha uma função que recebe um número inteiro e retorna o fatorial deste número. Esta função deve ainda verificar se é possível calcular o fatorial, se não for, ela deve de alguma forma retornar para a main que deu algum erro. A função main deve solicitar o valor do usuário e imprimir o fatorial dele, ou se não é possível calcular o fatorial.
#include <stdio.h>

int fat(int numFatorial);

void main()
{
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    printf("Fatorial de %d = %d ", numero, fat(numero));
    }

int fat(int numFatorial){
    int i, fatorial1 = 1;
    if(numFatorial < 0){
        printf("Nao e possivel calcular o fatorial de um numero negativo");
        return 0;
    }
    else{
        for(i = 1; i <= numFatorial; i++){
            fatorial1 = fatorial1 * i;
        }
        return fatorial1;
    }
}

