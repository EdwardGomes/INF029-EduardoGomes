/*12 Faça uma função recursiva que receba um número inteiro positivo N e imprima 
todos os números naturais de 0 até N em ordem crescente.
*/

#include <stdio.h>
#include <stdio.h>

void imprimeCrescente(int n);

int main (){

  imprimeCrescente(10);
}

void imprimeCrescente(int n){
  
 if (n != 0)
   imprimeCrescente(n-1);

   printf("%d\n", n);
}
