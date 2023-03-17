#include "Aluno.h"
#include <stdio.h>


int cadastrarAluno(Aluno lista[], int qtd);
void listarAlunos(Aluno lista[], int qtd);

int menuAluno(){
  int opcao;
  printf("Opções de Aluno\n");
  printf("0. Voltar\n");
  printf("1. Cadastrar\n");
  printf("2. Listar\n");
  printf("3. Excluir\n");
  scanf("%d", &opcao);
  return opcao;
}

int mainAluno(Aluno listaAluno[], int qtdAluno) { 
  int opcao = 1;

  while(opcao != 0){
    opcao = menuAluno();
    
    switch(opcao){
      case 1:{
        qtdAluno = cadastrarAluno(listaAluno, qtdAluno);
        break;
      }
      case 2:{
        listarAlunos(listaAluno, qtdAluno);
        break;
      }
      case 3:{
        break;
      }
    }
    
  }
  return qtdAluno;
}

int cadastrarAluno(Aluno lista[], int qtd){
  printf("#### Cadastrando aluno....\n");
  printf("Digite a matrícula: ");
  scanf("%d", &lista[qtd].matricula);
  printf("Digite a idade: ");
  scanf("%d", &lista[qtd].idade);
  qtd++;
  return qtd;
    
}

void listarAlunos(Aluno lista[], int qtd){
  printf("#### Lista de aluno....\n");
  for (int i = 0; i < qtd; i++){
    printf("Matrícula: %d - Idade: %d\n", lista[i].matricula, lista[i].idade );
  }  
}