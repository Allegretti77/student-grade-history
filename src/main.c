#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "csv_handler.h"

int main() {
    Aluno *alunos;
    int quantidade;

    alunos = lerCSV("entrada.csv", &quantidade);
    if (!alunos) {
        printf("Erro ao ler o arquivo CSV.\n");
        return 1;
    }

    exibirMenu(alunos, quantidade);

    free(alunos);
    return 0;
}
