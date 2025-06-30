#ifndef __PLAYER__
#define __PLAYER__

#include "Definitions.hpp"
#include "GameBoard.hpp"
#include "GameWindow.hpp"

class Player {

public:

    std::string name;
    int balance;
    int cellIndex = NOTAVAILABLEVALUE;
    int playerId = NOTAVAILABLEVALUE;

    int jailTurnCounter;
    bool isJailed = false;

    bool isParking = false;

    int pardonCardCounter = 0;

    static Player *makePlayer(std::string name, int balance, int cellIndex);

    void drawInactive(GameWindow *gameWindow, GameBoard *gameBoard);
    void drawActive(GameWindow *gameWindow, GameBoard *gameBoard);
    
private:

    int getRotateValue();

};

#endif // __PLAYER__
