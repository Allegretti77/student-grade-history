#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "analysis.h"

// Ordena os alunos por nota final usando Bubble Sort
Estatisticas ordenar_por_nota_bubble(Aluno *alunos, int n) {
    Estatisticas est = {0};
    clock_t inicio = clock();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            est.comparacoes++;
            if (alunos[j].media_final > alunos[j + 1].media_final) {
                Aluno temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }

    est.tempo_execucao = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    return est;
}

// Função auxiliar que realiza o merge de dois subarrays
void merge(Aluno *alunos, int esq, int meio, int dir, long *comparacoes) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    Aluno *L = malloc(n1 * sizeof(Aluno));
    Aluno *R = malloc(n2 * sizeof(Aluno));

    for (int i = 0; i < n1; i++) L[i] = alunos[esq + i];
    for (int j = 0; j < n2; j++) R[j] = alunos[meio + 1 + j];

    int i = 0, j = 0, k = esq;
    while (i < n1 && j < n2) {
        (*comparacoes)++;
        if (L[i].media_final <= R[j].media_final)
            alunos[k++] = L[i++];
        else
            alunos[k++] = R[j++];
    }

    while (i < n1) alunos[k++] = L[i++];
    while (j < n2) alunos[k++] = R[j++];

    free(L);
    free(R);
}

// Função recursiva do Merge Sort
void merge_sort(Aluno *alunos, int esq, int dir, long *comparacoes) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        merge_sort(alunos, esq, meio, comparacoes);
        merge_sort(alunos, meio + 1, dir, comparacoes);
        merge(alunos, esq, meio, dir, comparacoes);
    }
}

// Ordena os alunos por nota final usando Merge Sort
Estatisticas ordenar_por_nota_merge(Aluno *alunos, int n) {
    Estatisticas est = {0};
    clock_t inicio = clock();

    merge_sort(alunos, 0, n - 1, &est.comparacoes);

    est.tempo_execucao = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    return est;
}