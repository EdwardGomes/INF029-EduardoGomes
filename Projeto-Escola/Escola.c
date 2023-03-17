#include <stdio.h>
#define TAM 3
#include "professor.h"
#include "Aluno.h"

int imprimeMenu();

int imprimeMenu(){
  int opcao;
  printf("Digite a opção\n");
  printf("0. Sair\n");
  printf("1. Aluno\n");
  printf("2. Professor\n");
  printf("3. Disciplina\n");
  scanf("%d", &opcao);
  return opcao;
}

int main(void) {
  int mainAluno(Aluno listaAluno[], int qtdAluno);
  Aluno listaAluno[TAM];
  int qtdAluno = 0;
  int opcao = 1;

  int mainProfessor(Professor listaProfessor[], int qtdProfessor);
  Professor listaProfessor[TAM];
  int qtdProfessor = 0;
  int opcaoProfessor = 1;

  while(opcao != 0){
    opcao = imprimeMenu();

    switch (opcao){
      case 1:{
        qtdAluno = mainAluno(listaAluno, qtdAluno);
        break;
      }
      case 2:{
        qtdProfessor = mainProfessor(listaProfessor, qtdProfessor);
        break;
      }
      case 3:{
        printf("Opcao de Disciplina\n");
        break;
      }
      default:{
        printf("Opcao Inválida\n");
      }
    }

  }

  return 0;
}
