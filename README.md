# Maze Trapped

Este projeto é um jogo de labirinto onde o objetivo é encontrar o queijo no menor tempo possível. O labirinto é representado por uma matriz de células, onde cada célula pode ser um espaço livre ou uma parede.

Este projeto foi desenvolvido para a disciplina de Estrutura de Dados Lineares do curso de Análise e Desenvolvimento de Sistemas (ADS) com o objetivo de estudar a estrutura de dados Pilha.

## Estrutura do Projeto

- `main.cpp`: Arquivo principal que contém a lógica do jogo.
- `src/maze.cpp`: Implementação da classe `Maze` que representa o labirinto.
- `include/maze.h`: Declaração da classe `Maze`.
- `include/cell.h`: Declaração da classe `Cell` que representa uma célula do labirinto.
- `default.txt`: Arquivo de exemplo que contém a representação de um labirinto.

## Como Compilar

Para compilar o projeto, utilize o seguinte comando:

```sh
g++ .\main.cpp .\src\*.cpp -I .\include -o main.exe
```

## Como Executar
Após a compilação, execute o arquivo gerado:

```sh
./main.exe
```

## Arquivo de Labirinto
O arquivo `default.txt` contém a representação do labirinto. A primeira linha indica a largura e a altura do labirinto. As linhas seguintes representam as células do labirinto, onde `1` indica uma parede e `0` indica um espaço livre. O caractere `m` representa a posição inicial do jogador e `e` representa a posição do queijo.

Exemplo de arquivo `default.txt`:

```
5 5
1 1 1 1 1
1 m 0 0 1
1 1 0 1 1
1 0 0 e 1
1 1 1 1 1
``