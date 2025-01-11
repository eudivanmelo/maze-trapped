#include <string>

#ifndef MAZE_H
#define MAZE_H

#include "utils.h"

const char WALL = '1';
const char PATH = '0';
const char MOUSE = 'm';
const char CHEESE = 'e';

class Maze {
    private:
        struct Tile {
            bool isBlocked;
            bool visited = false;
        };

        Tile** tiles;
        int width, height;

        Position start, end;

    public:
        Maze(std::string filename);
        Maze(int width, int height);

        ~Maze();

        const int getWidth() const;
        const int getHeight() const;

        bool isBlocked(int x, int y) const;
        void setBlocked(int x, int y, bool blocked);

        bool isVisited(int x, int y) const;
        void setVisited(int x, int y, bool visited);

        const Position getStart() const;
        const Position getEnd() const;

        void setStart(int x, int y);
        void setEnd(int x, int y);
};;

#endif