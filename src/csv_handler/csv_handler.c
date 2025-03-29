#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv_handler.h"

Aluno* lerCSV(const char *arquivo, int *quantidade) {
    FILE *fp = fopen(arquivo, "r");
    if (!fp) return NULL;

    char linha[200];
    int count = 0;

    while (fgets(linha, sizeof(linha), fp)) count++;

    rewind(fp);

    Aluno *alunos = malloc(count * sizeof(Aluno));
    *quantidade = 0;

    while (fgets(linha, sizeof(linha), fp)) {
        sscanf(linha, "%d,%c,%c,%49[^,],%49[^,],%f",
            &alunos[*quantidade].semestre,
            &alunos[*quantidade].turma,
            &alunos[*quantidade].periodo,
            alunos[*quantidade].nome,
            alunos[*quantidade].disciplina,
            &alunos[*quantidade].media_final);
        (*quantidade)++;
    }

    fclose(fp);
    return alunos;
}

void salvarCSV(const char *nomeArquivo, Aluno *alunos, int quantidade) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    fprintf(arquivo, "Nome, Semestre, Turma, Periodo, Disciplina, Media Final\n");

    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%s, %d, %d, %d, %s, %.2f\n", 
                alunos[i].nome, 
                alunos[i].semestre, 
                alunos[i].turma, 
                alunos[i].periodo, 
                alunos[i].disciplina, 
                alunos[i].media_final);
    }

    fclose(arquivo);
    printf("Dados salvos no arquivo %s.\n", nomeArquivo);
}