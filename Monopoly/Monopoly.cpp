#include "GameWindow.hpp"

int main()
{
    GameWindow gameWindow;
    if (!gameWindow.generateGameBoard()) return 1;
    while (gameWindow.isOpen()) {
        gameWindow.update();
        gameWindow.clear();
        gameWindow.draw();
        gameWindow.display();
    }
    return 0;
}