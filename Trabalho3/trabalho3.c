/*3. Crie um programa que gerencie uma lista encadeada com todas as operações básicas. O programa deve ter arquivos para salvar e recuperar os dados da lista encadeada. Pense em como fazer implemntações de forma recursiva.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int info;
    struct No *prox;
}No;

struct No* criaNo(int info){
    struct No *novo = (struct No*)malloc(sizeof(struct No));
    novo->info = info;
    novo->prox = NULL;
    return novo;
}

void insereInicio(struct No **lista, int info){
    struct No *novo = criaNo(info);
    novo->prox = *lista;
    *lista = novo;
}

void insereFim(struct No **lista, int info){
    struct No *novo = criaNo(info);
    if(*lista == NULL){
        *lista = novo;
        return;
    }
    struct No *aux = *lista;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
}

void removerElemento(struct No **lista, int info){
    if(*lista == NULL){
        return;
    }
    struct No *aux = *lista;
    if(aux->info == info){
        *lista = aux->prox;
        free(aux);
        return;
    }
    while(aux->prox != NULL && aux->prox->info != info){
        aux = aux->prox;
    }
    if(aux->prox == NULL){
        return;
    }
    struct No *aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
}

void procurarElemento(struct No *lista, int info){
    if(lista == NULL){
        printf("Elemento nao encontrado\n");
        return;
    }
    if(lista->info == info){
        printf("Elemento encontrado\n");
        return;
    }
    procurarElemento(lista->prox, info);
}

void imprimirLista(struct No *lista){
    if(lista == NULL){
        printf("Lista vazia\n");
        return;
    }
    while(lista != NULL){
        printf("%d ", lista->info);
        lista = lista->prox;
    }
    printf("\n");
}

void saveListToFile(struct No *lista){
    FILE *file = fopen("lista.txt", "w");
    if(file == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    while(lista != NULL){
        fprintf(file, "%d ", lista->info);
        lista = lista->prox;
    }
    fclose(file);
}

void loadListFromFile(struct No **lista){
    FILE *file = fopen("lista.txt", "r");
    if(file == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    int info;
    while(fscanf(file, "%d", &info) != EOF){
        insereFim(lista, info);
    }
    fclose(file);
}



