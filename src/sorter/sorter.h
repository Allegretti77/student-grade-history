#ifndef SORTER_H
#define SORTER_H

#include "csv_handler.h"

void ordenarPorNome(Aluno *alunos, int numAlunos);
void ordenarPorSemestre(Aluno *alunos, int numAlunos);
void ordenarPorSemestreTurmaPeriodoDisciplinaNome(Aluno *alunos, int numAlunos);
void ordenarPorDisciplinaMediaFinal(Aluno *alunos, int numAlunos);
void ordenarPorPeriodoSemestreTurmaDisciplinaNome(Aluno *alunos, int numAlunos);

#endif