#include <stdio.h>
#include <stdlib.h>

struct No{
  int dado;
  struct No* prox;
};

void insert(struct No** cabeca, int valor){
  struct No* novoNo = (struct No*)malloc(sizeof(struct No));
  novoNo->dado = valor;
  novoNo->prox = NULL;

  if(*cabeca == NULL || valor <(*cabeca) -> dado) {
    novoNo->prox = *cabeca;
    *cabeca = novoNo;
  } else {
    struct No* atual = *cabeca;
    while (atual->prox != NULL && atual->prox->dado < valor){
      atual = atual->prox;
    }
    novoNo->prox = atual->prox;
    atual->prox = novoNo;
  }
}

  void imprimeLista(struct No* cabeca){
    struct No* atual = cabeca;
    while (atual != NULL) {
      printf("%d", atual->dado);
      atual = atual->prox;
    }
      printf("\n");
  }

  int main(){
    struct No* cabeca = NULL;

    insert(&cabeca, 5);
    insert(&cabeca, 2);
    insert(&cabeca, 10);
    insert(&cabeca, 7);

    imprimeLista(cabeca);

    return 0;
  }
  
