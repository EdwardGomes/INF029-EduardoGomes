#include "Aluno.h"
#include <stdio.h>
#include <time.h>
#include "professor.h"
#include <string.h>
#include "disciplina.h"

int cadastrarDisciplina(Disciplina lista[], int qtd);
void listarDisciplina(Disciplina lista[], int qtd);

int menuDisciplina(){
  int opcao;
  int c;
  printf("Opções de Disciplina\n");
  printf("0. Voltar\n");
  printf("1. Cadastrar Disciplina\n");
  printf("2. Vizualizar Disciplinas\n");
  printf("3. Excluir\n");
  printf("4. Atualizar\n");
  scanf("%d", &opcao);
  while ((c = getchar()) != '\n' && c != EOF); 
  return opcao;
}

int mainDisciplina(Disciplina listaDisciplina[], int qtdDisciplina) { 
  int opcao = 1;

  while(opcao != 0){
    opcao = menuDisciplina();
    
    switch(opcao){
      case 1:{
        qtdProfessor = cadastrarDisciplina(listaDisciplina, qtdDisciplina);
        break;
      }
      case 2:{
        listarDisciplina(listaDisciplinar, qtdDisciplina);
        if (qtdDisciplina == 0){
          printf("Lista de Disciplinas Vazia\n");
        }
        break;
      }
      case 3: {
      printf("Excluir Disciplina\n");
      printf("Digite a Disciplina: \n");
      int matricula;
      scanf("%d", &matricula);
      int achou = 0;
      if (matricula < 0) {
        printf("Matrícula Inválida");
        break;
      } else {
      for (int i = 0; i < qtdProfessor; i++) {
        if (matricula == listaProfessor[i].matriculaP) {
          listaProfessor[i].ativoP = -1;
          for (int j = i; j < qtdProfessor - 1; j++) {
            listaProfessor[j].matriculaP = listaProfessor[j+1].matriculaP;
            listaProfessor[j].idadeP = listaProfessor[j+1].idadeP;
            listaProfessor[j].ativoP = listaProfessor[j+1].ativoP;
            strcpy(listaProfessor[j].nomeP, listaProfessor[j+1].nomeP);
            strcpy(listaProfessor[j].disciplinaP, listaProfessor[j+1].disciplinaP);
            listaProfessor[j].sexoP = listaProfessor[j+1].sexoP;
          }
        listaProfessor[qtdProfessor-1].matriculaP = 0;
        listaProfessor[qtdProfessor-1].idadeP = 0;
        listaProfessor[qtdProfessor-1].ativoP = 0;
        strcpy(listaProfessor[qtdProfessor-1].nomeP, "");
        strcpy(listaProfessor[qtdProfessor-1].disciplinaP, "");
        listaProfessor[qtdProfessor-1].sexoP = 'X';
        qtdProfessor--;
        achou = 1;
        break;
      }
    }
    if (achou)
      printf("Disciplina Excluído com Sucesso!\n");
    else 
      printf("Disciplina Inexistente\n");
  }
  break;
}
          case 4: {
    printf("Atualizar Disciplina\n");
    printf("Digite a Disciplina: \n");
    int matricula;
    scanf("%d", &matricula);
    int achou = 0;
    if (matricula < 0){
        printf("Matrícula Inválida");
        break;
    } else {
        for (int i = 0; i < qtdProfessor; i++) {
            if (matricula == listaDisciplina[i].matriculaP && listaDisciplina[i].ativoP) {
               
                printf("Digite o novo nome: \n");
                char novoNome[50];
                scanf(" %[^\n]s", novoNome);
                printf("Digite a nova idade: \n");
                int novaIdade;
                scanf("%d", &novaIdade);
                printf("Digite a nova disciplina: \n");
                char novaDisciplina[50];
                scanf(" %[^\n]s", novaDisciplina);

                strcpy(listaDisciplina[i].nomeP, novoNome);
                strcpy(listaDisciplina[i].disciplinaP, novaDisciplina);
                achou = 1;
                break;
            }
        }
        if (achou)
            printf("Disciplina Atualizado com Sucesso!\n");
        else 
            printf("Matrícula Inexistente\n");
    }
    break;
}
    }  
  }
    return qtdDisciplina;
  }

    int cadastrarDisciplina(Disciplina lista[], int qtd) {
    printf("#### Cadastrando Disciplina....\n");

    
  }

    
    