

typedef struct Disciplina {
    int matriculaProfessor;
    char nome[50];
    char disciplina[50];
    int horario;
    char professor[50];
    int ativo;
} Disciplina;

int mainDisciplina(Disciplina listaDisciplina[], int qtdDisciplina, int listaProfessor[], int qtdProfessor);