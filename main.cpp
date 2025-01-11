#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "include/maze.h"
#include "include/stack.h"

#ifdef _WIN32
#define WINDOWS_SYSTEM
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

void renderMaze(Maze *maze);
Maze *loadMaze_fromfile(std::string filename);
void wait(int seconds);
void clear();

int main()
{
    Stack BackTracking = Stack(100);

    string filename;
    cout << "Informe o nome do arquivo, ou deixe em branco (arquivo.txt): ";
    getline(cin, filename);

    if (filename.empty()) {
        filename = "default.txt";
    }

    Maze maze(filename);

    string getPosition;
    cout << "Informe a posição inicial, ou deixe em branco (x y): ";
    getline(cin, getPosition);
    
    if (!getPosition.empty()) {
        istringstream iss(getPosition);
        int x, y;
        iss >> x >> y;
        maze.setVisited(maze.getStart().x, maze.getStart().y, false);
        maze.setStart(x, y);
    }

    getPosition = "";
    cout << "Informe a posição final, ou deixe em branco (x y): ";
    getline(cin, getPosition);
    
    if (!getPosition.empty()) {
        istringstream iss(getPosition);
        int x, y;
        iss >> x >> y;
        maze.setEnd(x, y);
    }

    string mazeString;

    renderMaze(&maze);
    cout << "Pressione ENTER para iniciar a busca..." << endl;
    cin.get();

    while (maze.getStart().x != maze.getEnd().x || maze.getStart().y != maze.getEnd().y)
    {
        for (const auto &dir : DIRECTIONS)
        {
            int newX = maze.getStart().x + dir.first;
            int newY = maze.getStart().y + dir.second;

            if (newX >= 0 && newX < maze.getWidth() &&
                newY >= 0 && newY < maze.getHeight() &&
                !maze.isBlocked(newX, newY) &&
                !BackTracking.contains(Position{newX, newY}) &&
                !maze.isVisited(newX, newY))
            {
                BackTracking.push(Position{newX, newY});
            }
        }

        clear();

        if (BackTracking.isEmpty())
        {
            cout << "Não foi possível encontrar um caminho!" << endl;
            system("pause");
            return 0;
        }

        // Movimentar
        cout << "Pilha: " << BackTracking << endl;
        cout << "POS: " << BackTracking.peek().x << ", " << BackTracking.peek().y << endl;

        Position newStart = BackTracking.pop();        
        maze.setStart(newStart.x, newStart.y);

        renderMaze(&maze);
        wait(1);
    }

    cout << "Chegou ao destino!" << endl;
    system("pause");
    return 0;
}

void renderMaze(Maze *maze)
{
    string mazeString = "";

    for (int y = 0; y < maze->getHeight(); y++)
    {
        for (int x = 0; x < maze->getWidth(); x++)
        {
            if (maze->getStart().x == x && maze->getStart().y == y)
            {
                mazeString += "MM";
                continue;
            }

            if (maze->getEnd().x == x && maze->getEnd().y == y)
            {
                mazeString += "EE";
                continue;
            }

            mazeString += (maze->isBlocked(x, y) ? "##" : "  ");
        }
        mazeString += "\n";
    }

    cout << mazeString;
}

void clear()
{
#ifdef __linux__
    system("clear");
#else
    system("cls");
#endif
}

void wait(int seconds)
{
#ifdef WINDOWS_SYSTEM
    Sleep(seconds * 1000);
#else
    sleep(seconds);
#endif
}