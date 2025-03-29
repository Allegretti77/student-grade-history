#ifndef CSV_HANDLER_H
#define CSV_HANDLER_H

typedef struct {
    int semestre;
    char turma;
    char periodo;
    char nome[100];
    char disciplina[50];
    float media_final;
} Aluno;

Aluno* lerCSV(const char *arquivo, int *quantidade);
void salvarCSV(const char *arquivo, Aluno *alunos, int quantidade);

#endif