#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define TAM 10

#include "EstruturaVetores.h"

int *vetorPrincipal[TAM];
int qtd[TAM];
int tamVetor[TAM];
int vetorFull[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    int retorno = 0;
    
    // se posição é um valor válido {entre 1 e 10}
    if (posicao < 1 || posicao > 10){
      //  printf("invalid position for structure\n");
        return POSICAO_INVALIDA;
      
    }
    // a posicao pode já existir estrutura auxiliar
    if (vetorPrincipal[posicao-1] != NULL){
       // printf("already has auxiliary structure\n");
    return JA_TEM_ESTRUTURA_AUXILIAR;

    }
    
    // o tamanho nao pode ser menor que 1
    if (tamanho < 1){
      // printf("invalid size\n");
    return TAMANHO_INVALIDO;

    }

   vetorPrincipal[posicao-1] = (int *)malloc(tamanho * sizeof(int));
   tamVetor[TAM] = tamanho;
  
    // o tamanho ser muito grande
    if (!vetorPrincipal[posicao-1]){
       // printf("invalid size\n");
    return SEM_ESPACO_DE_MEMORIA;

    }
    // deu tudo certo, crie
    //printf ("creating auxiliary structure\n");
      
    return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int temEspaco = 0;

    if (posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }
  
        // testar se existe a estrutura auxiliar
        if (vetorPrincipal[posicao-1] == NULL)
        {
            return SEM_ESTRUTURA_AUXILIAR;
        }
        
        // testar se a estrutura auxiliar tem espaço
        for (int i = 0; i <= TAM; i++){
            if (vetorPrincipal[posicao-1][i] == 0){
                temEspaco = i;
                break;
            }
        }
        //insere
        if (temEspaco <= posicao){
            vetorPrincipal[posicao-1][temEspaco] = valor;// inserir o valor na posição
            qtd[posicao-1]++;
            //printf("Value inserted successfully in %d, %d\n", posicao, valor);
            return SUCESSO;
        }
        else
        {  
            //printf("No space\n");
            return SEM_ESPACO;
       }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
  
    if (posicao < 1 || posicao > 10)
    {
        return POSICAO_INVALIDA;
    }
 
        // testa se existe a estrutura auxiliar
    if (vetorPrincipal[posicao-1] == NULL)
        {
            return SEM_ESTRUTURA_AUXILIAR;
        }

    // se a estrutura estiver vazia
    if (qtd[posicao-1] == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    // se a estrutura não estiver vazia
  
    qtd[posicao-1]--;
    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int i, j;
    int contPosicao = 0;

    if (posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[posicao-1] == NULL)
        {
          return SEM_ESTRUTURA_AUXILIAR;
        }
    if (qtd[posicao-1] == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }    
    // Percorre a estrutura auxiliar na posição indicada
    for (i = 0; i < TAM; i++){
        // Se encontrar o valor desejado
        if (vetorPrincipal[posicao-1][i] == valor){
            // Move os elementos seguintes um índice para trás
            for (j = i; j < TAM - 1; j++) {
                vetorPrincipal[posicao-1][j] = vetorPrincipal[posicao-1][j+1];
            }
            // Incrementa o contador de posições removidas
            contPosicao++;
            // Decrementa o contador de posições ocupadas
            qtd[posicao-1]--;
            // Sai do loop
            break;
        } 
    }
    // Verifica se algum elemento foi removido
    if (contPosicao > 0){
        return SUCESSO;
    }
    else
    {
        return NUMERO_INEXISTENTE;
    }
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int i;
    int retorno = 0;
  
    if (posicao < 1 || posicao > 10)
    {
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[posicao-1] == NULL)
        {
          return SEM_ESTRUTURA_AUXILIAR;
        }

    if (qtd[posicao-1] == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
     // Copia os elementos da estrutura auxiliar na posição especificada para o vetorAux
    for (i = 0; i < qtd[posicao-1]; i++){
        vetorAux[i] = *(vetorPrincipal[posicao-1]+i);
    }
  
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int i;

    if (posicao < 1 || posicao > 10)
    {
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[posicao-1] == NULL)
        {
          return SEM_ESTRUTURA_AUXILIAR;
        }
    // Copia os elementos da estrutura auxiliar na posição especificada para o vetorAux
    for (i = 0; i < qtd[posicao-1]; i++){
        vetorAux[i] = *(vetorPrincipal[posicao-1]+i);
    }
    // Ordena os elementos do vetorAux em ordem crescente (bubble sort)
    for (int i = 0; i < qtd[posicao-1]; i++){
        for (int j = i+1; j < qtd[posicao-1]; j++){
            if (vetorAux[i] > vetorAux[j]){
                int aux = vetorAux[i];
                vetorAux[i] = vetorAux[j];
                vetorAux[j] = aux;

            }
        }
    }
    return SUCESSO;     
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0;
    int j = 0;
    int contador = 0;
    int quantidade = 0;
    // Percorre o vetorPrincipal 
    for (int i = 0; i < TAM; i++){
        // Se a estrutura auxiliar na posição i não for nula
        if (qtd[i] != NULL){
            quantidade = quantidade + qtd[i]; // Soma a quantidade de elementos da estrutura auxiliar na posição i
        }
    }
     // Percorre todas as estruturas auxiliares novamente
    for (int i = 0; i < TAM; i++){
        // verifica se a estrutura auxiliar está vazia e se é nula
        if (qtd[i] == 0 && vetorPrincipal[i] == NULL){
            contador++;
        }
        else {
            // Copia os elementos da estrutura auxiliar na posição i para o vetorAux
            for (int k = 0; k < qtd[i]; k++){
                vetorAux[j] = *(vetorPrincipal[i]+k);
                j++;// Incrementa o contador de posições do vetorAux
            }
        }
    }
    // verifica se todas as estruturas auxiliares estão vazias
    if (contador == TAM){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    else {
        return SUCESSO;
    }
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int contador = 0, contador1 = 0, j = 0;
    int quantidade;
    int retorno = 0;
    // percore as estruturas auxiliares
    for (int i = 0; i < TAM; i++){
        if (qtd[i] != NULL){// verifica se a estrutura auxiliar na posição i não é nula
            quantidade = quantidade + qtd[i];// Soma a quantidade de elementos da estrutura auxiliar na posição i
        }
    }
    // percore as estruturas auxiliares novamente
    for (int i = 0; i < TAM; i++){
        if (qtd[i] == 0 && vetorPrincipal[i] == NULL){// verifica se a estrutura auxiliar está vazia e se é nula
            contador++;// Incrementa o contador de estruturas auxiliares vazias
        }
        else {
            // Copia os elementos da estrutura auxiliar na posição i para o vetorAux
            for (int k = 0; k < qtd[i]; k++){
                vetorAux[j] = *(vetorPrincipal[i]+k);
                j++;
            }
        }
    }
    // verifica se todas as estruturas auxiliares estão vazias
    if (contador == TAM){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    else {
        // Ordena os elementos do vetorAux em ordem crescente (bubble sort)
        for (int i = 0; i < quantidade; i++){
            for (int j = i+1; j < quantidade; j++){
                if (vetorAux[i] > vetorAux[j]){
                    int aux = vetorAux[i];
                    vetorAux[i] = vetorAux[j];
                    vetorAux[j] = aux;
                }
            }
        }
    }
    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int i, tamanhoFinal;
    int retorno = 0;

    tamanhoFinal = tamVetor[posicao-1] + novoTamanho;

    if (posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }

    else if (tamanhoFinal > TAM){
        return SEM_ESPACO_DE_MEMORIA;
    }

    else if (vetorPrincipal[posicao-1] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }

    else if (novoTamanho < 0){
        return NOVO_TAMANHO_INVALIDO;
    }

    else {
        // Aloca o novo tamanho para a estrutura auxiliar na posição posicao-1
        vetorPrincipal[posicao-1] = (int*) realloc(vetorPrincipal[posicao-1], tamanhoFinal*sizeof(int));
        tamVetor[posicao-1] = tamanhoFinal;
        return SUCESSO;
    }

    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    int retorno = 0;

    if (posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }

    if (qtd[posicao-1] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (vetorPrincipal[posicao-1] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }

    else {
        return qtd[posicao-1];
    }

    if (qtd[posicao-1] == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/

void inicializar()
{  
  for (int i = 0; i < TAM; i++){
      vetorPrincipal[i] = NULL;
      qtd[i] = 0;
      vetorFull[i] = 0;
  }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/

void finalizar()
{
  for (int i = 0; i < TAM; i++){
   free (vetorPrincipal[i]);
  }
}