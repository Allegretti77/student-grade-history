#include <stdio.h>
#include "menu.h"
#include "sorter.h"
#include "csv_handler.h"

void exibirMenu(Aluno *alunos, int quantidade) {
    int opcao;
    do {
        printf("\nMenu de Ordenação\n");
        printf("1 - Ordenar por Nome\n");
        printf("2 - Ordenar por Semestre\n");
        printf("3 - Ordenar por Semestre, Turma, Período, Disciplina e Nome\n");
        printf("4 - Ordenar por Disciplina e Média Final (decrescente)\n");
        printf("5 - Ordenar por Período, Semestre, Turma, Disciplina e Nome\n");
        printf("6 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

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
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 6);
}
