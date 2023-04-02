#include <stdio.h>
#include <string.h>
#include "disciplina.h"
#include "professor.h"
#include "Aluno.h"

#define MAX_DISCIPLINAS 100

int cadastrarDisciplina(Disciplina lista[], int qtd, Professor listaProfessor[], int qtdProfessor);
void listarDisciplinas(Disciplina lista[], int qtd);

int menuDisciplina() {
    int opcao;
    int c;
    printf("Opções de Disciplina\n");
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

int mainDisciplina(Disciplina listaDisciplina[], int qtdDisciplina, Professor listaProfessor[], int qtdProfessor) {
    int opcao = 1;

    while (opcao != 0) {
        opcao = menuDisciplina();

        switch (opcao) {
            case 1: {
                qtdDisciplina = cadastrarDisciplina(listaDisciplina, qtdDisciplina, listaProfessor, qtdProfessor);
                break;
            }
            case 2: {
                listarDisciplinas(listaDisciplina, qtdDisciplina);
                if (qtdDisciplina == 0) {
                    printf("Lista de Disciplinas Vazia\n");
                }
                break;
            }
        }
    }
    return 0;
}

int verificarProfessor(Professor lista[], int qtd, int matricula) {
    for (int i = 0; i < qtd; i++) {
        if (lista[i].matriculaP == matricula && lista[i].ativoP == 1) {
            // Professor já cadastrado
            return 1;
        }
    }
    // Professor não encontrado
    return 0;
}

int cadastrarDisciplina(Disciplina lista[], int qtd, Professor listaProfessor[], int qtdProfessor) {
    printf("#### Cadastrando disciplina....\n");

    char nome[50];
    int input_valido = 0;
    while (!input_valido) {
        printf("Digite o nome da disciplina: ");
        if (fgets(nome, 50, stdin) != NULL) {
            if (nome[0] != '\n') { // Verifica se o usuário digitou algo
                nome[strcspn(nome, "\n")] = '\0';
                input_valido = 1;
            }
        }
    }

    // Verifica se o professor já está cadastrado
    int matriculaProfessor;
    int professorEncontrado = 0;
    while (!professorEncontrado) {
        printf("Digite a matricula do professor responsável: ");
        scanf("%d", &matriculaProfessor);
        professorEncontrado = verificarProfessor(listaProfessor, qtdProfessor, matriculaProfessor);
        if (!professorEncontrado) {
            printf("Professor não encontrado. Tente novamente.\n");
        }
    }

    // Adiciona a nova disciplina na lista
    strcpy(lista[qtd].nome, nome);
    lista[qtd].matriculaProfessor = matriculaProfessor;
    lista[qtd].ativo = 1;
    printf("Disciplina Cadastrada com Sucesso!\n");

    qtd++;

    return qtd;
}
