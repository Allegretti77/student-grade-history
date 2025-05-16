#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "csv_handler.h"

typedef struct {
    double tempo_execucao;
    long comparacoes;
} Estatisticas;

// Ordena por nota usando Bubble Sort e coleta estatísticas
Estatisticas ordenar_por_nota_bubble(Aluno *alunos, int n);

// Ordena por nota usando Merge Sort e coleta estatísticas
Estatisticas ordenar_por_nota_merge(Aluno *alunos, int n);

#endif