#include <stdio.h>
#include <string.h>
#include "sorter.h"

void ordenarPorNome(Aluno alunos[], int numAlunos) {
    for (int i = 0; i < numAlunos - 1; i++) {
        for (int j = i + 1; j < numAlunos; j++) {
            if (strcmp(alunos[i].nome, alunos[j].nome) > 0) {
                Aluno temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }
}

void ordenarPorSemestre(Aluno alunos[], int numAlunos) {
    for (int i = 0; i < numAlunos - 1; i++) {
        for (int j = i + 1; j < numAlunos; j++) {
            if (alunos[i].semestre > alunos[j].semestre) {
                Aluno temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }
}

void ordenarPorSemestreTurmaPeriodoDisciplinaNome(Aluno *alunos, int numAlunos) {
    for (int i = 0; i < numAlunos - 1; i++) {
        for (int j = i + 1; j < numAlunos; j++) {
            if (alunos[i].semestre > alunos[j].semestre || 
                (alunos[i].semestre == alunos[j].semestre && alunos[i].turma > alunos[j].turma) ||
                (alunos[i].semestre == alunos[j].semestre && alunos[i].turma == alunos[j].turma && alunos[i].periodo > alunos[j].periodo) ||
                (alunos[i].semestre == alunos[j].semestre && alunos[i].turma == alunos[j].turma && alunos[i].periodo == alunos[j].periodo && strcmp(alunos[i].disciplina, alunos[j].disciplina) > 0) ||
                (alunos[i].semestre == alunos[j].semestre && alunos[i].turma == alunos[j].turma && alunos[i].periodo == alunos[j].periodo && strcmp(alunos[i].disciplina, alunos[j].disciplina) == 0 && strcmp(alunos[i].nome, alunos[j].nome) > 0)) {
                Aluno temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }
    printf("Ordenação por semestre, turma, período, disciplina e nome concluída.\n");
}

void ordenarPorDisciplinaMediaFinal(Aluno alunos[], int numAlunos) {
    for (int i = 0; i < numAlunos - 1; i++) {
        for (int j = i + 1; j < numAlunos; j++) {
            if (strcmp(alunos[i].disciplina, alunos[j].disciplina) > 0 ||
                (strcmp(alunos[i].disciplina, alunos[j].disciplina) == 0 && alunos[i].media_final < alunos[j].media_final)) {
                Aluno temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }
}

void ordenarPorPeriodoSemestreTurmaDisciplinaNome(Aluno alunos[], int numAlunos) {
    for (int i = 0; i < numAlunos - 1; i++) {
        for (int j = i + 1; j < numAlunos; j++) {
            if (alunos[i].periodo > alunos[j].periodo ||
                (alunos[i].periodo == alunos[j].periodo && alunos[i].semestre > alunos[j].semestre) ||
                (alunos[i].periodo == alunos[j].periodo && alunos[i].semestre == alunos[j].semestre && alunos[i].turma > alunos[j].turma) ||
                (alunos[i].periodo == alunos[j].periodo && alunos[i].semestre == alunos[j].semestre && alunos[i].turma == alunos[j].turma && strcmp(alunos[i].disciplina, alunos[j].disciplina) > 0) ||
                (alunos[i].periodo == alunos[j].periodo && alunos[i].semestre == alunos[j].semestre && alunos[i].turma == alunos[j].turma && strcmp(alunos[i].disciplina, alunos[j].disciplina) == 0 && strcmp(alunos[i].nome, alunos[j].nome) > 0)) {
                Aluno temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }
}