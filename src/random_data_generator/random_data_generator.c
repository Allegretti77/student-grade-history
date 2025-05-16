#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random_data_generator.h"

const char *disciplinas[] = {"matematica", "portugues", "geografia"};

// Gera dados aleatórios de alunos e salva no arquivo especificado
void gerar_entrada_aleatoria(const char *arquivo, int quantidade) {
    FILE *fp = fopen(arquivo, "w");
    if (!fp) {
        perror("Erro ao criar arquivo CSV aleatório");
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < quantidade; i++) {
        int ano = 2010 + rand() % 14;
        char nome[100];
        snprintf(nome, sizeof(nome), "Aluno%d", rand() % 10000);
        const char *disciplina = disciplinas[rand() % 3];
        float nota = ((float) rand() / RAND_MAX) * 10.0;
        fprintf(fp, "%d,A,N,%s,%s,%.2f\n", ano, nome, disciplina, nota);
    }

    fclose(fp);
    printf("Arquivo '%s' gerado com %d alunos.\n", arquivo, quantidade);
}