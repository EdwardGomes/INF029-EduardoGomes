// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Eduardo Reis Gomes
//  email: edugomes514@gmail.com
//  Matrícula: 20212160057
//  Semestre: 2023.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "EduardoGomes20212160057.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */

int q1(char data[])
{
  int datavalida = 1;
  int diasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  //quebrar a string data em strings sDia, sMes, sAno
  DataQuebrada dataQuebrada = quebraData(data);
  if (dataQuebrada.valido == 0) return 0;
  
  char strAno[5];
  sprintf(strAno, "%d", dataQuebrada.iAno);
  int ano = atoi(strAno);

  if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) { // verifica se o ano é bissexto
      diasMes[1] = 29; // adiciona um dia no mês de fevereiro
  }
  
  if (dataQuebrada.iMes < 1 || dataQuebrada.iMes > 12) datavalida = 0; // verifica se o mês é válido
  else if (dataQuebrada.iDia < 1 || dataQuebrada.iDia > diasMes[dataQuebrada.iMes - 1])  datavalida = 0; //Verifica se o valor do dia é válido para o mês fornecido, utilizando a matriz "diasMes" para verificar o número de dias em cada mês. 
  //-1 é utilizado para acessar a posição correta da matriz, pois cada mês é representado por um número de 1 a 12, enquanto a matriz é indexada de 0 a 11.
     
  //printf("%s\n", data);

  if (datavalida)
      return 1;
  else
      return 0;
}


/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{
    
    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }
    else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }
      //calcule a distancia entre as datas
      DataQuebrada dataInicialQuebrada = quebraData(datainicial);//*quebra a data inicial
      DataQuebrada dataFinalQuebrada = quebraData(datafinal);//*quebra a data final

      int anoInicial = dataInicialQuebrada.iAno;
      int anoFinal = dataFinalQuebrada.iAno;
      int mesInicial = dataInicialQuebrada.iMes;
      int mesFinal = dataFinalQuebrada.iMes;
      int diaInicial = dataInicialQuebrada.iDia;
      int diaFinal = dataFinalQuebrada.iDia;

      dma.qtdAnos = anoFinal - anoInicial;//calcula a diferença de anos
      dma.qtdMeses = mesFinal - mesInicial;//calcula a diferença de meses
      dma.qtdDias = diaFinal - diaInicial;//calcula a diferença de dias

      if (dma.qtdDias < 0){//se a diferença de dias for negativa, soma 1 ao mês e subtrai 30 dias
        dma.qtdDias += 30;
        dma.qtdMeses -= 1;
      }

      if (dma.qtdMeses < 0){//se a diferença de meses for negativa, soma 1 ao ano e subtrai 12 meses
        dma.qtdMeses += 12;
        dma.qtdAnos -= 1;
      }

      if (dma.qtdAnos < 0){//se a diferença de anos for negativa, retorna 4
        dma.retorno = 4;
        return dma;
      }

      //se tudo der certo
      if (dma.qtdAnos >= 0 && dma.qtdMeses >= 0 && dma.qtdDias >= 0){
        dma.retorno = 1;
        return dma;}    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
  
    for (int i = 0; texto[i] != '\0' && i < 250; i++) {
        char letraTexto = texto[i];
    if (!isCaseSensitive) {//se a pesquisa não for case sensitive, converte os caracteres para minúsculo
      
        letraTexto = tolower(letraTexto); //armazena o caractere atual em minúsculo
        c = tolower(c);//armazena o caractere de comparação em minúsculo
    }
      if (letraTexto == c){ //se o caractere atual for igual ao da comparação
        qtdOcorrencias++; //incrementa as ocorrências
      }  
    }
        
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que i índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
  
    int qtdOcorrencias = 0;
    int i, j;

    //*Não funciona para a segunda frase do teste

    for (i = 0; strTexto[i] != '\0'; i++) {//percorre o texto base
      int contador = 0;

      for (j = 0; strBusca[j] != '\0'; j++) {//percorre a palavra de busca
          
      if (strTexto[i + j] == strBusca[j]) {//se o caractere atual for igual ao da palavra de busca
        contador++;
        }

      // Se o contador for igual ao tamanho da palavra buscada, significa que a palavra foi encontrada
      
      if (contador == strlen(strBusca)) {
          qtdOcorrencias++;
       // Armazena a posição de início e fim da palavra no vetor de posições
          posicoes[qtdOcorrencias * 2 - 2] = i + 1;// posição inicial
          posicoes[qtdOcorrencias * 2 - 1] = i + strlen(strBusca);// posição final
          } 
      }
    }
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int temp;
    int numInvert = 0;
  
    while (num != 0) {
      temp = num %10; //Armazena o último digito do numero original em Temp
      numInvert = numInvert * 10 + temp; // insere o dígito armazenado em 'temp' como o novo dígito mais significativo em 'numInvert'
      num = num / 10; //remove o último digito de Num
    }
  
    return numInvert;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    char numBase[11];
    sprintf(numBase, "%d", numerobase);//converte o número base para string
    char numBuscaStr[11];
    sprintf(numBuscaStr, "%d", numerobusca);//converte o número de busca para string

    for (int i = 0; i < strlen(numBase); i++)
    {
      bool match = true;
      // Percorre a string numBuscaStr
      for (int j = 0; j < strlen(numBuscaStr); j++)
      {
            // Verifica se os dígitos correspondentes são iguais
            if (numBase[i + j] != numBuscaStr[j])
            {
            // Se houver diferença, o match é falso e o loop interno é quebrado     
            match = false;
            break;
            }
      }
        //Se todos os dígitos correspondentes forem iguais, incrementa a quantidade de ocorrências
        if (match) {
          qtdOcorrencias++;
        
            }  
        }
    
    return qtdOcorrencias;
}