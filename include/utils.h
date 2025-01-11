#ifndef UTILS_H
#define UTILS_H

#include <array>

const std::array<std::pair<int, int>, 4> DIRECTIONS = {
    std::make_pair(0, -1),  // Cima
    std::make_pair(0, 1),  // Baixo
    std::make_pair(-1, 0), // Esquerda
    std::make_pair(1, 0)  // Direita
};

struct Size {
    int width;
    int height;
};

struct Position {
    int x;
    int y;
};

#endif