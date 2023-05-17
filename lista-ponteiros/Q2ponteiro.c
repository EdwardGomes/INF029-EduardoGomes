/*2) Faça um programa que tenha uma função troca que recebe dois parâmetros inteiros e troque o valor das variáveis um pelo outro. A função main deve ler do usuário os dois valores, chamar a função troca, e depois imprimir os valores trocados.*/

int achou = 0, i;
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

    for (i = 0; i < vetorFull[posicao-1]; i++){
      if (vetorPrincipal[posicao-1][i] == valor){
        achou++;
      }
      while (contPosicao < vetorFull[posicao-1]){
        vetorPrincipal[posicao-1][i] = vetorPrincipal[posicao-1][i+1];
        contPosicao++;
      }
    vetorFull[posicao-1]--;
    }
    
    if (achou > 0){
      return SUCESSO;
    }
    else{
      return NUMERO_INEXISTENTE;
    }