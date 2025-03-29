
# student data organizer:

## Descrição:
Este projeto é um gerenciador de dados de alunos em C, que lê um arquivo CSV contendo informações dos alunos e permite ordenar esses dados de acordo com diferentes critérios, como nome, semestre, turma, período, disciplina, e média final.

## Estrutura de Arquivos:
A estrutura do projeto é a seguinte:

```
.
├── bin
│   └── student-data-organizer
├── entrada.csv
├── Makefile
├── README.md
├── saida.csv
└── src
    ├── csv_handler
    │   ├── csv_handler.c
    │   └── csv_handler.h
    ├── main.c
    ├── menu
    │   ├── menu.c
    │   └── menu.h
    └── sorter
        ├── sorter.c
        └── sorter.h
```

## Como Compilar:
Para compilar o projeto, basta usar o comando:

```sh
make
```

Este comando irá compilar o código fonte e gerar o executável `student-data-organizer` na pasta `bin`.

## Como Executar:
Para rodar o projeto, execute o seguinte comando:

```sh
./bin/student-data-organizer
```

Ao rodar o programa, ele lerá o arquivo `entrada.csv`, exibirá um menu de opções para ordenar os dados dos alunos, e salvará os dados ordenados no arquivo `saida.csv`.

## Estrutura dos Arquivos CSV:

O arquivo de entrada `entrada.csv` deve estar no seguinte formato:

```
Gabriel,7.5,A,A,Computação,9.0
Guilherme,8.5,B,B,Matemática,7.8
Vinicius,7.8,C,C,Engenharia,8.2
```

- **entrada.csv** contém informações dos alunos, incluindo nome, semestre, turma, período, disciplina, e média final.
- **saida.csv** será gerado após a execução do programa, contendo os dados ordenados de acordo com a opção escolhida no menu.

## Funcionalidades:
O projeto possui as seguintes funcionalidades:

- **Leitura de arquivos CSV**: O programa lê o arquivo CSV `entrada.csv` com as informações dos alunos.
- **Ordenação de alunos**: O programa oferece diferentes opções de ordenação dos alunos, incluindo por nome, semestre, turma, período, disciplina e média final.
- **Gravação em CSV**: Após a ordenação, o programa salva os dados no arquivo `saida.csv`.
- **Menu interativo**: O programa oferece um menu para que o usuário escolha a forma de ordenação dos dados.

As opções de ordenação disponíveis são:
1. Ordenar por Nome
2. Ordenar por Semestre
3. Ordenar por Semestre, Turma, Período, Disciplina e Nome
4. Ordenar por Disciplina e Média Final (decrescente)
5. Ordenar por Período, Semestre, Turma, Disciplina e Nome
6. Sair

## Como Usar:
1. Compile o projeto com `make`.
2. Execute o programa com `./bin/student-data-organizer`.
3. Escolha a opção de ordenação desejada.
4. O arquivo `saida.csv` será gerado com os dados ordenados.

# Integrantes do grupo:
- Gabriel Ferreira - RA: 10442043
- Guilherme Limeira de Souza - RA: 10439777
- Vinicius Barbosa Pereira Allegretti - RA: 10437502
