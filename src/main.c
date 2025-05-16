#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "csv_handler.h"

int main() {
    Aluno *alunos = NULL;
    int quantidade = 0;
    int continuar = 1;

    while (continuar) {
        // Lê os dados do arquivo csv e armazena no array de alunos
        free(alunos);
        alunos = lerCSV("entrada.csv", &quantidade);
        if (!alunos) {
            printf("Aviso: Não foi possível carregar os dados de 'entrada.csv'.\n");
            alunos = NULL;
            quantidade = 0;
        }

        // Exibe o menu e permite escolher uma ação
        continuar = exibirMenu(alunos, quantidade);
    }

    free(alunos);
    return 0;
}