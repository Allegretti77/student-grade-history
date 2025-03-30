#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "csv_handler.h"

int main() {
    Aluno *alunos;
    int quantidade;

    // Lê os dados do arquivo csv e armazena no array de alunos
    alunos = lerCSV("entrada.csv", &quantidade);
    if (!alunos) {
        printf("Erro ao ler o arquivo CSV.\n");
        return 1;
    }

    // Exibe o menu para o usuário escolher um critério de ordenação
    exibirMenu(alunos, quantidade);

    // Libera a memória alocada para os alunos
    free(alunos);
    return 0;
}