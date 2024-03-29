#include "Aluno.h"
#include <stdio.h>
#include <time.h>
#include "professor.h"
#include <string.h>
#include "disciplina.h"

int cadastrarAluno(Aluno lista[], int qtd);
void listarAlunos(Aluno lista[], int qtd);
void excluirAluno(Aluno listaAluno[], int *qtdAluno);
int atualizarAluno(Aluno lista[], int qtd);
void atualizarAlunoInfo(Aluno* aluno);

int menuAluno() {
    int opcao;
    int c;
    printf("Opções de Aluno\n");
    printf("0. Voltar\n");
    printf("1. Cadastrar\n");
    printf("2. Listar\n");
    printf("3. Excluir\n");
    printf("4. Atualizar\n");
    scanf("%d", &opcao);
    while ((c = getchar()) != '\n' && c != EOF) {
        // limpa o buffer de entrada
    }
    return opcao;
}

int mainAluno(Aluno listaAluno[], int qtdAluno) {
    int opcao = 1;

    while (opcao != 0) {
        opcao = menuAluno();

        switch (opcao) {
            case 1: {
                qtdAluno = cadastrarAluno(listaAluno, qtdAluno);
                break;
            }
            case 2: {
                listarAlunos(listaAluno, qtdAluno);
                if (qtdAluno == 0) {
                    printf("Lista de Alunos Vazia\n");
                }
                break;
            }
            case 3: {
                excluirAluno(listaAluno, &qtdAluno);
                break;
            }
            case 4: {
                qtdAluno = atualizarAluno(listaAluno, qtdAluno);
                break;
            }
        }
   
  }
}
  int cadastrarAluno(Aluno lista[], int qtd) {
    printf("#### Cadastrando aluno....\n");

    // Gerador de matricula
    srand(time(NULL));
    int matricula = rand() % 100000;

    // Checa se o número gerado já existe
    int encontrado = 0;
    for (int i = 0; i < qtd; i++) {
        if (lista[i].matricula == matricula) {
            encontrado = 1;
            break;
        }
    }

    // Se a matricula já existe, gera uma nova
    while (encontrado) {
        matricula = rand() % 100000;
        encontrado = 0;
        for (int i = 0; i < qtd; i++) {
            if (lista[i].matricula == matricula) {
                encontrado = 1;
                break;
            }
        }
    }

    char nome[50];
    int input_valido = 0;
    while (!input_valido) {
        printf("Digite o nome do Aluno: ");
        if (fgets(nome, 50, stdin) != NULL) {
            if (nome[0] != '\n') { // Verifica se o usuário digitou algo
                nome[strcspn(nome, "\n")] = '\0';
                input_valido = 1;
            }
        }
    }

    strcpy(lista[qtd].nome, nome);

    int idade;
    printf("Digite a idade: ");
    scanf("%d", &lista[qtd].idade);

    printf("Digite o sexo (M para masculino, F para feminino): ");
    char sexo;
    scanf(" %c", &sexo);
  
    if (sexo == 'M') {
        lista[qtd].sexo = 'M';
    } else if (sexo == 'F') {
        lista[qtd].sexo = 'F';
    } else {
        printf("Sexo inválido! Usando sexo indefinido.\n");
        lista[qtd].sexo = 'X';
    }
    
    // Adiciona o novo aluno a struct
    lista[qtd].matricula = matricula;
    lista[qtd].ativo = 1;
    printf("Aluno Cadastrado com Sucesso!\n");

    qtd++;

    return qtd;
}

void listarAlunos(Aluno lista[5], int qtd) {
    printf("#### Lista de alunos....\n");
    for (int i = 0; i < qtd; i++) {
        printf("Nome: %s - Matrícula: %d - idade: %d sexo: %c\n", lista[i].nome, lista[i].matricula, lista[i].idade, lista[i].sexo);
    }  
}

void excluirAluno(Aluno listaAluno[], int *qtdAluno) {
  printf("Excluir Aluno\n");
  printf("Digite a Matrícula: \n");
  int matricula;
  scanf("%d", &matricula);
  int achou = 0;
  if (matricula < 0) {
    printf("Matrícula Inválida");
  } else {
    for (int i = 0; i < *qtdAluno; i++) {
      if (matricula == listaAluno[i].matricula) {
        listaAluno[i].ativo = -1;
        for (int j = i; j < *qtdAluno - 1; j++) {
          listaAluno[j].matricula = listaAluno[j + 1].matricula;
          listaAluno[j].idade = listaAluno[j + 1].idade;
          listaAluno[j].ativo = listaAluno[j + 1].ativo;
          strcpy(listaAluno[j].nome, listaAluno[j + 1].nome);
          listaAluno[j].sexo = listaAluno[j + 1].sexo;
        }
        listaAluno[*qtdAluno - 1].matricula = 0;
        listaAluno[*qtdAluno - 1].idade = 0;
        listaAluno[*qtdAluno - 1].ativo = 0;
        strcpy(listaAluno[*qtdAluno - 1].nome, "");
        listaAluno[*qtdAluno - 1].sexo = 'X';
        (*qtdAluno)--;
        achou = 1;
        break;
      }
    }
    if (achou) {
      printf("Aluno Excluído com Sucesso!\n");
    } else {
      printf("Matrícula Inexistente\n");
    }
  }
}

int atualizarAluno(Aluno listaAluno[], int qtdAluno) {
    printf("Atualizar Aluno\n");
    printf("Digite a Matrícula: \n");
    int matricula;
    scanf("%d", &matricula);
    int achou = 0;

    if (matricula < 0){
        printf("Matrícula Inválida");
        return qtdAluno;
    } else {
        for (int i = 0; i < qtdAluno; i++) {
            if (matricula == listaAluno[i].matricula && listaAluno[i].ativo) {
                // chama a função para pegar a atualização
                atualizarAlunoInfo(&listaAluno[i]);
                achou = 1;
                break;
            }
        }
        if (achou) {
            printf("Aluno Atualizado com Sucesso!\n");
        } else {
            printf("Matrícula Inexistente\n");
        }
    }
    return qtdAluno;
}

void atualizarAlunoInfo(Aluno *aluno) {
    printf("Digite a nova Matrícula: \n");
    int novaMatricula;
    scanf("%d", &novaMatricula);
    printf("Digite o novo nome: \n");
    char novoNome[50];
    scanf(" %[^\n]s", novoNome);
    printf("Digite a nova idade: \n");
    int novaIdade;
    scanf("%d", &novaIdade);

    aluno->matricula = novaMatricula;
    aluno->idade = novaIdade;
    strcpy(aluno->nome, novoNome);
}




