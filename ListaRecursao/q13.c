/*13 Faça uma função recursiva que receba um número inteiro positivo N e imprima 
todos os números naturais de 0 até N em ordem decrescente.
*/

#include <stdio.h>
#include <stdio.h>

void imprime(int n);

int main (){

  imprime(10);
}

void imprime(int n){

 printf("%d\n", n); 
 if (n != 0)
   imprime(n-1);

}
