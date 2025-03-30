#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "sorter.h"
#include "csv_handler.h"

void exibirMenu(Aluno *alunos, int quantidade) {
    int opcao;
    char entrada[100];

    do {
        // Exibe as opções de ordenação disponíveis
        printf("\nMenu de Ordenação\n");
        printf("1 - Ordenar por Nome\n");
        printf("2 - Ordenar por Semestre\n");
        printf("3 - Ordenar por Semestre, Turma, Período, Disciplina e Nome\n");
        printf("4 - Ordenar por Disciplina e Média Final (decrescente)\n");
        printf("5 - Ordenar por Período, Semestre, Turma, Disciplina e Nome\n");
        printf("6 - Sair\n");

        do {
            printf("Escolha uma opção: ");
            fgets(entrada, sizeof(entrada), stdin);

            // Valida se a entrada é um número entre 1 e 6
            if (sscanf(entrada, "%d", &opcao) != 1) {
                printf("Entrada inválida. Digite um número entre 1 e 6.\n");
                opcao = 0;
            }
        } while (opcao < 1 || opcao > 6);

        // Executa a ordenação correspondente à opção escolhida
        switch (opcao) {
            case 1:
                ordenarPorNome(alunos, quantidade);
                break;
            case 2:
                ordenarPorSemestre(alunos, quantidade);
                break;
            case 3:
                ordenarPorSemestreTurmaPeriodoDisciplinaNome(alunos, quantidade);
                break;
            case 4:
                ordenarPorDisciplinaMediaFinal(alunos, quantidade);
                break;
            case 5:
                ordenarPorPeriodoSemestreTurmaDisciplinaNome(alunos, quantidade);
                break;
            case 6:
                printf("Saindo...\n");
                break;
        }

        // Salva os dados ordenados no arquivo csv após cada operação
        salvarCSV("saida.csv", alunos, quantidade);
    } while (opcao != 6);
}