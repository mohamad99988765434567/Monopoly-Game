#ifndef __GAMEWINDOW__
#define __GAMEWINDOW__

#include <SFML/Graphics.hpp>

#include "Definitions.hpp"
#include "GameCell.hpp"
#include "GameBoard.hpp"

/* 
 * This class create and manage a Monopoly game with all default settings (40 spaces, classic board, classic rule)
 */
class GameWindow {

private:

    sf::RenderWindow mRenderWindow;
    bool mIsStop = false;

    GameBoard *mGameBoard = NULL;
    int mScreenWidth = NOTAVAILABLEVALUE;
    int mScreenHeight = NOTAVAILABLEVALUE;
    int mCellBaseSize;

    int mPlayersInfoX = NOTAVAILABLEVALUE;
    int mCellAndActivePlayerInfo = NOTAVAILABLEVALUE;

    int mCurrentCell = NOTAVAILABLEVALUE;

    sf::Font mFont;
    int mFontSize[5];
    const sf::Color mPlayerColor[8] = {sf::Color::Red, sf::Color::Yellow, sf::Color::Green, sf::Color::Blue, GAMEDEFINITION_BROWN, GAMEDEFINITION_SKYBLUE, GAMEDEFINITION_PURPLE, GAMEDEFINITION_ORANGE};

    sf::Clock mGameClock;
    bool mGameClockRestarted = false;

public:

    sf::Texture startTexture;
    sf::Texture parkingTexture;
    sf::Texture gotoJailTexture;
    sf::Texture jailTexture;
    sf::Texture chestTexture;
    sf::Texture chanceTexture;
    sf::Texture taxTexture;
    sf::Texture railroadTexture;
    sf::Texture electricCompanyTexture;
    sf::Texture waterCompanyTexture;
    sf::Texture playerTexture[8];

public:

    GameWindow();
    ~GameWindow();

    void create();
    void destroy();

    bool isOpen();

    void update();
    void clear() { mRenderWindow.clear(); };
    void draw();
    void display() { mRenderWindow.display(); };

    void draw(const sf::Drawable &drawable, const sf::RenderStates &states = sf::RenderStates::Default) {
        mRenderWindow.draw(drawable, states);
    }
    void drawText(std::string str, int fontSize, sf::Color color, int x, int y, int rotage = 0, bool centerAlign = false);

    int getCellBaseSize() { return mCellBaseSize; }
    sf::Color getPlayerFlagColor(int playerIdx);
    GameBoard *getGameBoard() { return mGameBoard; }

    bool generateGameBoard();
    void calculateGameBoardLayout();

    void showCurrentInfo();
    void showActivePlayerAssets();
    void showGameLogs();

    bool processArrowKeys(sf::Keyboard::Key code);
    void displayAvailableActions(int x, int y, int dy);
    bool processActionKeys(sf::Keyboard::Key code);

    void showStateNotEnoughPlayer();
    void processStateNotEnoughPlayer(sf::Keyboard::Key code);
    void showStateManageAssetsOrRollDice();
    void processStateManageAssetsOrRollDice(sf::Keyboard::Key code);
    void showStateManageAssetsOrNextPlayer();
    void processStateManageAssetsOrNextPlayer(sf::Keyboard::Key code);
    void showStateWaitForChestValue();
    void processStateWaitForChestValue();
    void showStateWaitForChanceValue();
    void processStateWaitForChanceValue();

    void showStateNegativeBalance();
    void processStateNegativeBalance(sf::Keyboard::Key code);
    void showStateBankrupt();
    void processStateBankrupt(sf::Keyboard::Key code);

};

#endif // __GAMEWINDOW__

