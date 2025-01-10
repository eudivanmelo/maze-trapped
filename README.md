# Aplicação de Pilha: Trapped Mouse

## Tarefas
[ ] Definir a estrutura do projeto
- Criar uma classe Cell com os seguintes elementos:
    - Atributos privados: int x e int y.
    - Sobrecarga do operador ==.

- Criar uma classe Maze com:
    - Atributos privados:
        - Cell currentCell, exitCell, entryCell.
        - const char exitMarker, entryMarker, visited, passage, wall.
        - Pilha de células (stack<Cell> mazeStack).
        - Array bidimensional de caracteres (std::vector<std::string> maze).
    - Métodos públicos:
        - void exitMaze() para implementar a lógica de saída.

[ ] Lógica para inicialização do labirinto
- Implementar uma função para ler o labirinto de entrada (teclado ou arquivo).
- Deduzir automaticamente as dimensões do labirinto.
- Adicionar paredes externas ao labirinto.
- Garantir que apenas os caracteres 1, 0, e e m sejam aceitos.

[ ] Implementar algoritmo de saída do labirinto
- Utilizar uma pilha para rastrear o caminho.
- Implementar lógica de Backtracking:
    - Marcar células visitadas com o caractere ..
    - Testar direções na ordem: direita, esquerda, baixo, cima.
    - Retroceder para a última posição válida em caso de beco sem saída.

[ ] Adicionar funcionalidade de animação
- Animação no terminal: Exibir cada passo do rato no labirinto.

## Arquivo do mapa

O arquivo terá em seu contéudo algumas informações que representarão os objetos no mapa

- `e`: representará a saída
- `m`: representará a posição inicial do rato
- `0` (zero): são os corredores
- `1` (um): são as paredes