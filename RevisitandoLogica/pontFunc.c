#include <stdio.h>

int troca(int *a, int *b){
  int aux;
  int *pAux;
  pAux = &aux;
  
  *pAux = *a;
  *a = *b;
  *b = *pAux;  
}
int main(){
  int a, b, aux;
  int *x, *y, *z;
  printf("Valor de a: ");
  scanf("%d", &a);
  printf("Digite b: ");
  scanf("%d", &b);
  troca(&a, &b);
  
  printf("Valor de a: %d\n", a);
  printf("Valor de b: %d\n", b);

}
