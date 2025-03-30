#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "sorter.h"
#include "csv_handler.h"

void exibirMenu(Aluno *alunos, int quantidade) {
    int opcao;
    char entrada[100];

    do {
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

            if (sscanf(entrada, "%d", &opcao) != 1) {
                printf("Entrada inválida. Digite um número entre 1 e 6.\n");
                opcao = 0;
            }
        } while (opcao < 1 || opcao > 6);

        switch (opcao) {
            case 1:
                ordenarPorNome(alunos, quantidade);
                salvarCSV("saida.csv", alunos, quantidade);
                break;
            case 2:
                ordenarPorSemestre(alunos, quantidade);
                salvarCSV("saida.csv", alunos, quantidade);
                break;
            case 3:
                ordenarPorSemestreTurmaPeriodoDisciplinaNome(alunos, quantidade);
                salvarCSV("saida.csv", alunos, quantidade);
                break;
            case 4:
                ordenarPorDisciplinaMediaFinal(alunos, quantidade);
                salvarCSV("saida.csv", alunos, quantidade);
                break;
            case 5:
                ordenarPorPeriodoSemestreTurmaDisciplinaNome(alunos, quantidade);
                salvarCSV("saida.csv", alunos, quantidade);
                break;
            case 6:
                salvarCSV("saida.csv", alunos, quantidade);
                printf("Saindo...\n");
                break;
        }
    } while (opcao != 6);
}
