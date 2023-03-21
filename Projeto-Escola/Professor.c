#include "professor.h"
#include "Aluno.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

int cadastrarProfessor(Professor listaP[], int qtdP);
void listarProfessor(Professor listaP[], int qtdP);
void excluirProfessor(Professor listaProfessor[], int *qtdProfessor); 
void atualizarProfessor(Professor *listaProfessor, int qtdProfessor);
int buscarProfessorPorMatricula(Professor *listaProfessor, int qtdProfessor, int matricula);


int menuProfessor(){
  int opcao;
  int c;
  printf("Opções de Professor\n");
  printf("0. Voltar\n");
  printf("1. Cadastrar\n");
  printf("2. Listar\n");
  printf("3. Excluir\n");
  printf("4. Atualizar\n");
  scanf("%d", &opcao);
  while ((c = getchar()) != '\n' && c != EOF); 
  return opcao;
}

int mainProfessor(Professor listaProfessor[], int qtdProfessor) { 
  int opcao = 1;

  while(opcao != 0){
    opcao = menuProfessor();
    
    switch(opcao){
      case 1:{
        qtdProfessor = cadastrarProfessor(listaProfessor, qtdProfessor);
        break;
      }
      case 2:{
        listarProfessor(listaProfessor, qtdProfessor);
        if (qtdProfessor == 0){
          printf("Lista de Professores Vazia\n");
        }
        break;
      }
      case 3: {
        printf("Excluir Professor\n");
        excluirProfessor(listaProfessor, &qtdProfessor); 
        break;
}
     
      case 4: {
        atualizarProfessor(listaProfessor, qtdProfessor);
        break;
}
    }            
  }
}
int cadastrarProfessor(Professor listaP[], int qtd) {
    printf("#### Cadastrando Professor....\n");

    // Gerador de matricula
    srand(time(NULL));
    int matricula = rand() % 100000;

    // Checa se o número gerado já existe
    int encontrado = 0;
    for (int i = 0; i < qtd; i++) {
        if (listaP[i].matriculaP == matricula) {
            encontrado = 1;
            break;
        }
    }
    // Se a matricula já existe, gera uma nova
    while (encontrado) {
        matricula = rand() % 100000;
        encontrado = 0;
        for (int i = 0; i < qtd; i++) {
            if (listaP[i].matriculaP == matricula) {
                encontrado = 1;
                break;
            }
        }
    }
    char nome[50];
    int input_valido = 0;
    while (!input_valido) {
        printf("Digite o nome do professor: ");
        if (fgets(nome, 50, stdin) != NULL) {
            if (nome[0] != '\n') { // Verifica se o usuário digitou algo
                nome[strcspn(nome, "\n")] = '\0';
                input_valido = 1;
            }
        }
    }
    strcpy(listaP[qtd].nomeP, nome);

    char disciplina[50];
    input_valido = 0;
    while (!input_valido) {
        printf("Digite a disciplina do professor: ");
        if (fgets(disciplina, 50, stdin) != NULL) {
            if (disciplina[0] != '\n') { 
                disciplina[strcspn(disciplina, "\n")] = '\0';
                input_valido = 1;
            }
        }
    }
    strcpy(listaP[qtd].disciplinaP, disciplina);  
    
      int idade;
      printf("Digite a idade: ");
      scanf("%d", &listaP[qtd].idadeP);

      printf("Digite o sexo (M para masculino, F para feminino): ");
      char sexo;
      scanf(" %c", &sexo);
  
    if(sexo == 'M') {
    listaP[qtd].sexoP = 'M';
    } else if(sexo == 'F') {
    listaP[qtd].sexoP = 'F';
    } else {
    printf("Sexo inválido! Usando sexo indefinido.\n");
    listaP[qtd].sexoP = 'X';
    }
  
    listaP[qtd].matriculaP = matricula;
    listaP[qtd].ativoP = 1;
    
    printf("Professor Cadastrado com Sucesso!\n");

    qtd++;

    return qtd;
    
}

void listarProfessor(Professor listaP[], int qtdP){
  printf("#### Lista de Professores....\n");
  for (int i = 0; i < qtdP; i++){
    
    printf("Nome: %s - Disciplina: %s - Matrícula: %d - idade: %d sexo: %c\n", listaP[i].nomeP, listaP[i].disciplinaP, listaP[i].matriculaP, listaP[i].idadeP, listaP[i].sexoP);
  }  
  }

void excluirProfessor(Professor listaProfessor[], int *qtdProfessor) {
  printf("Digite a Matrícula: \n");
  int matricula;
  scanf("%d", &matricula);
  int achou = 0;
  if (matricula < 0) {
    printf("Matrícula Inválida");
    return;
  }
  for (int i = 0; i < *qtdProfessor; i++) {
    if (matricula == listaProfessor[i].matriculaP) {
      listaProfessor[i].ativoP = -1;
      for (int j = i; j < *qtdProfessor - 1; j++) {
        listaProfessor[j].matriculaP = listaProfessor[j+1].matriculaP;
        listaProfessor[j].idadeP = listaProfessor[j+1].idadeP;
        listaProfessor[j].ativoP = listaProfessor[j+1].ativoP;
        strcpy(listaProfessor[j].nomeP, listaProfessor[j+1].nomeP);
        strcpy(listaProfessor[j].disciplinaP, listaProfessor[j+1].disciplinaP);
        listaProfessor[j].sexoP = listaProfessor[j+1].sexoP;
      }
      listaProfessor[*qtdProfessor-1].matriculaP = 0;
      listaProfessor[*qtdProfessor-1].idadeP = 0;
      listaProfessor[*qtdProfessor-1].ativoP = 0;
      strcpy(listaProfessor[*qtdProfessor-1].nomeP, "");
      strcpy(listaProfessor[*qtdProfessor-1].disciplinaP, "");
      listaProfessor[*qtdProfessor-1].sexoP = 'X';
      (*qtdProfessor)--;
      achou = 1;
      break;
    }
  }
  if (achou) {
    printf("Professor Excluído com Sucesso!\n");
  } else {
    printf("Matrícula Inexistente\n");
  }
}

void atualizarProfessor(Professor *listaProfessor, int qtdProfessor) {
    printf("Atualizar Professor\n");
    printf("Digite a Matrícula: \n");
    int matricula;
    scanf("%d", &matricula);

    int achou = buscarProfessorPorMatricula(listaProfessor, qtdProfessor, matricula);
    if (achou != -1) {
        printf("Digite a nova Matrícula: \n");
        int novaMatricula;
        scanf("%d", &novaMatricula);
        printf("Digite o novo nome: \n");
        char novoNome[50];
        scanf(" %[^\n]s", novoNome);
        printf("Digite a nova idade: \n");
        int novaIdade;
        scanf("%d", &novaIdade);
        printf("Digite a nova disciplina: \n");
        char novaDisciplina[50];
        scanf(" %[^\n]s", novaDisciplina);

        listaProfessor[achou].matriculaP = novaMatricula;
        listaProfessor[achou].idadeP = novaIdade;
        strcpy(listaProfessor[achou].nomeP, novoNome);
        strcpy(listaProfessor[achou].disciplinaP, novaDisciplina);

        printf("Professor Atualizado com Sucesso!\n");
    } else {
        printf("Matrícula Inexistente\n");
    }
}

int buscarProfessorPorMatricula(Professor *listaProfessor, int qtdProfessor, int matricula) {
    if (matricula < 0) {
        printf("Matrícula Inválida");
        return -1;
    }

    for (int i = 0; i < qtdProfessor; i++) {
        if (matricula == listaProfessor[i].matriculaP && listaProfessor[i].ativoP) {
            return i;
        }
    }

    return -1;
}
