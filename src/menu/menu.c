#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "sorter.h"
#include "csv_handler.h"
#include "random_data_generator.h"
#include "analysis.h"


int exibirMenu(Aluno *alunos, int quantidade) {
    int opcao;
    char entrada[100];

    do {
        printf("\nMenu de Ordenação\n");
        printf("1 - Ordenar por Nome\n");
        printf("2 - Ordenar por Semestre\n");
        printf("3 - Ordenar por Semestre, Turma, Período, Disciplina e Nome\n");
        printf("4 - Ordenar por Disciplina e Média Final (decrescente)\n");
        printf("5 - Ordenar por Período, Semestre, Turma, Disciplina e Nome\n");
        printf("6 - Gerar entrada aleatória\n");
        printf("7 - Ordenar por nota (Bubble Sort)\n");
        printf("8 - Ordenar por nota (Merge Sort)\n");
        printf("9 - Sair\n");

        printf("Escolha uma opção: ");
        fgets(entrada, sizeof(entrada), stdin);
        sscanf(entrada, "%d", &opcao);

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
            case 6: {
                int qtd;
                printf("Quantidade de alunos para gerar: ");
                fgets(entrada, sizeof(entrada), stdin);
                sscanf(entrada, "%d", &qtd);
                gerar_entrada_aleatoria("entrada.csv", qtd);
                break;
            }
            case 7: {
                Estatisticas est = ordenar_por_nota_bubble(alunos, quantidade);
                salvarCSV("saida_bubble.csv", alunos, quantidade);
                printf("Algoritmo: Bubble Sort\nTamanho da entrada: %d\nTempo: %.4fs\nComparações: %ld\n",
                       quantidade, est.tempo_execucao, est.comparacoes);
                break;
            }
            case 8: {
                Estatisticas est = ordenar_por_nota_merge(alunos, quantidade);
                salvarCSV("saida_merge.csv", alunos, quantidade);
                printf("Algoritmo: Merge Sort\nTamanho da entrada: %d\nTempo: %.4fs\nComparações: %ld\n",
                       quantidade, est.tempo_execucao, est.comparacoes);
                break;
            }
            case 9:
                printf("Encerrando...\n");
                return 0;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao < 1 || opcao > 9);

    return 1;
}