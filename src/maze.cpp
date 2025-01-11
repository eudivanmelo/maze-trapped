#include "../include/maze.h"

#include <sstream>
#include <fstream>

#include <iostream>

/**
 * @brief Construtor da classe Maze que inicializa o labirinto a partir de um arquivo.
 * 
 * @param filename O nome do arquivo que contém a representação do labirinto.
 * 
 * @throws std::runtime_error Se o arquivo não puder ser aberto.
 * 
 * O construtor lê o arquivo linha por linha para determinar a largura e altura do labirinto.
 * Cada linha do arquivo representa uma linha do labirinto, onde '1' indica uma parede (isBlocked = true)
 * e qualquer outro caractere indica um espaço livre (isBlocked = false).
 * 
 * @note Possíveis erros:
 * - O código assume que todas as linhas do arquivo têm o mesmo comprimento, o que pode não ser o caso.
 */
Maze::Maze(std::string filename) {
    std::ifstream file(filename);

    // Verifica se o arquivo foi aberto corretamente
    if (!file.is_open()){
        throw std::runtime_error("Não foi possível abrir o arquivo " + filename);
        return;
    }

    std::string line;
    width = 0, height = 0;

    getline(file, line);
    std::stringstream ss(line);
    ss >> width >> height;

    tiles = new Tile*[width];
    for(int i = 0; i < width; i++){
        tiles[i] = new Tile[height];
    }

    for(int y = 0; y < height; y++){
        getline(file, line);
        std::stringstream ss(line);

        for(int x = 0; x < width; x++){
            char value;
            ss >> value;

            if (value == '1'){
                tiles[x][y].isBlocked = true;
            } else if (value == '0'){
                tiles[x][y].isBlocked = false;
            } else if (value == 'm'){
                tiles[x][y].isBlocked = false;
                setStart(x, y);
            } else if (value == 'e'){
                tiles[x][y].isBlocked = false;
                setEnd(x, y);
            }
        }
    }
}

Maze::~Maze(){
    for(int i = 0; i < getHeight(); i++){
        delete[] tiles[i];
    }
    delete[] tiles;
}

const int Maze::getHeight() const {
    return height;
}

const int Maze::getWidth() const {
    return width;
}

bool Maze::isBlocked(int x, int y) const {
    return tiles[x][y].isBlocked;
}

void Maze::setBlocked(int x, int y, bool blocked){
    tiles[x][y].isBlocked = blocked;
}

bool Maze::isVisited(int x, int y) const {
    return tiles[x][y].visited;
}

void Maze::setVisited(int x, int y, bool visited){
    tiles[x][y].visited = visited;
}

const Position Maze::getStart() const {
    return start;
}

const Position Maze::getEnd() const {
    return end;
}

void Maze::setStart(int x, int y){
    this->start = Position{x, y};
    tiles[x][y].visited = true;
}

void Maze::setEnd(int x, int y){
    this->end = Position{x, y};
}