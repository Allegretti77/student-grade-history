#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv_handler.h"

// Lê o arquivo csv e armazena os dados em um array de alunos
Aluno* lerCSV(const char *arquivo, int *quantidade) {
    FILE *fp = fopen(arquivo, "r");
    if (!fp) return NULL;

    char linha[200];
    int count = 0;

    // Conta a quantidade de linhas no arquivo
    while (fgets(linha, sizeof(linha), fp)) count++;
    rewind(fp);

    // Aloca memória para armazenar os alunos
    Aluno *alunos = malloc(count * sizeof(Aluno));
    *quantidade = 0;

    // Lê os dados do arquivo e preenche o array de alunos
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

// Salva os dados dos alunos em um arquivo csv
void salvarCSV(const char *nomeArquivo, Aluno *alunos, int quantidade) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    // Escreve o cabeçalho no arquivo csv
    fprintf(arquivo, "Nome, Semestre, Turma, Periodo, Disciplina, Media Final\n");

    // Escreve os dados de cada aluno no arquivo
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