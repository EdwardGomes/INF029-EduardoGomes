/*10) Escreva uma função recursiva que determine quantas vezes um dígito K ocorre 
em um número natural N. Por exemplo, o dígito 2 ocorre 3 vezes em 762021192.
*/

#include <stdio.h>
#include <stdlib.h>

int ocorrencias(int n, int k){
    if(n == 0){
        return 0;
    }
    if(n%10 == k){
        return 1 + ocorrencias(n/10, k);
    }
    return ocorrencias(n/10, k);
}

int main(){
    int n, k;
    printf("Digite um numero: ");
    scanf("%d", &n);
    printf("Digite um digito: ");
    scanf("%d", &k);
    printf("O digito %d ocorre %d vezes no numero %d", k, ocorrencias(n, k), n);
    return 0;
}