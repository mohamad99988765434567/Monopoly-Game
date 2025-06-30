#ifndef __GAMEBOARD__
#define __GAMEBOARD__

#include "Definitions.hpp"
#include "GameCell.hpp"
#include "Player.hpp"
#include "GameWindow.hpp"

class GameBoard {

private:

    GameState mGameState = GameState::NotEnoughPlayer;
    int mWinnerId = NOTAVAILABLEVALUE;
    int mActivePlayerId = NOTAVAILABLEVALUE;
    int mNextAvaiableId = 0;

    int m_side = 40;

    int mDoubleCount = 0;
    int lastDice = 0;
    bool mNegativeBeforeRollingDice;

    int mJailIndex = NOTAVAILABLEVALUE;
    int mStartIndex = NOTAVAILABLEVALUE;

    int mPlayerHouses = NOTAVAILABLEVALUE;
    int mPlayerHotels = NOTAVAILABLEVALUE;
    int mPlayerCells = NOTAVAILABLEVALUE;
    int mPlayerTotalAssetValue = NOTAVAILABLEVALUE;

public:

    GameWindow *mGameWindow = NULL;
    std::vector<GameCell *> cells;
    std::vector<Player *> players;

    std::vector<std::string> gameLogs;

    GameBoard() {}
    ~GameBoard();

    void setGameWindow(GameWindow *gameWindow) { mGameWindow = gameWindow; }

    void appendCell(GameCell *cell);
    bool appendPlayer(Player *player);

    void draw();

    GameState getGameState() { return mGameState; }

    void appendLog(std::string str);
    void createLog(std::string str);

    int getActivePlayerId() { return mActivePlayerId; }
    GameCell *getGameCellAt(int idx);
    Player *getPlayerFromId(int playerId);
    Player *getActivePlayer() { return getPlayerFromId(mActivePlayerId); }
    int getActivePlayerCellCounter() { return mPlayerCells; }
    int getActivePlayerHouseCounter() { return mPlayerHouses; }
    int getActivePlayerHotelCounter() { return mPlayerHotels; }
    int getActivePlayerTotalAssetValue() { return mPlayerTotalAssetValue; }
    

    bool startGame();
    bool nextPlayer();
    bool checkGameOver();
    int getWinnerId() { return mWinnerId; }
    void updateActivePlayerAssets();

    bool isActionAllowed(GameAction action, int cellIndex = NOTAVAILABLEVALUE);
    bool pushAction(GameAction action, int cellIndex = NOTAVAILABLEVALUE);

    bool pushDice(int dice1, int dice2);
    bool pushChestValue(int val);
    bool pushChanceValue(int val);

    void processRentFeeAtNewCell();

    void removeActivePlayer();

private:

    void checkAndRewardIfPassedStartCell(int oldIndex, int newIndex);
    void justMovedActivePlayerToTheNewCell();
    bool pushDice_DoubleSubTask(int dice1, int dice2);

    bool teleportPlayer(std::string name, std::string foundMessage);
    bool teleportPlayer(CellType type, std::string foundMessage);

    void addActivePlayerBalance(int amount, bool diceNotRolled);
};

#endif // __GAMEBOARD__
