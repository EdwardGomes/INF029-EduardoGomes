/*Faça um programa que verifique se um número é primo*/
#include <stdio.h>

int main(){
  int n, div, primo;
  printf("Digite um número: ");
  scanf("%d", &n);
  primo = 1;
  if(n<=1){
    primo=0;
  }

  for(div = 2; div<=n/2 && primo==1; div++){
    if(n%div==0){
      primo = 0;
    }
  }

  if(primo == 1){
    printf("\nO número %d é primo.\n", n);
  }else{
    printf("\nO número %d não é primo.\n", n);
  }
}