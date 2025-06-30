#ifndef __GAMECELL__
#define __GAMECELL__

#include "Definitions.hpp"
#include "GameBoard.hpp"
#include "GameWindow.hpp"

class GameCell {

public:

    CellType type = CellType::Undefined;
    StreetGroup group = StreetGroup::Undefined;
    std::string name = "";

    int owner = NOTAVAILABLEVALUE;

    int price = NOTAVAILABLEVALUE;
    int upgradeLevel = NOTAVAILABLEVALUE;
    int housePrice = NOTAVAILABLEVALUE;

    int rentCost = NOTAVAILABLEVALUE;
    int rentCostWithHouse = NOTAVAILABLEVALUE;
    int rentCostWithHotel = NOTAVAILABLEVALUE;

    // drawing part

    int rectX = NOTAVAILABLEVALUE;
    int rectY = NOTAVAILABLEVALUE;
    int rectHeight = NOTAVAILABLEVALUE;
    int rectWidth = NOTAVAILABLEVALUE;
    CellPosition cellPosition = CellPosition::Undefined;

    bool cellSpriteOn = false;
    sf::Sprite cellSprite;

    void draw(GameWindow *gameWindow);

    // make new cells

    static GameCell *makeStartCell(sf::Texture *texture);
    static GameCell *makeFreeParkingCell(sf::Texture *texture);
    static GameCell *makeGotoJailCell(sf::Texture *texture);
    static GameCell *makeJailCell(sf::Texture *texture);
    static GameCell *makeChestCell(sf::Texture *texture, CellPosition cellPosition);
    static GameCell *makeChanceCell(sf::Texture *texture, CellPosition cellPosition);
    static GameCell *makeTaxCell(sf::Texture *texture, CellPosition cellPosition);
    static GameCell *makeRailroadCell(sf::Texture *texture, CellPosition cellPosition, std::string name, int price);
    static GameCell *makeCompanyCell(sf::Texture *texture, CellPosition cellPosition, std::string name, int price);
    static GameCell *makeStreetCell(StreetGroup group, CellPosition cellPosition, std::string name, int price);

    //

    void drawCellInfo(GameWindow *gameWindow, int x, int y);

private:

    static GameCell *makeFullSquareCell(sf::Texture *texture, CellType type);
    static GameCell *makeFullRectangleSpriteCell(sf::Texture *texture, CellPosition cellPosition, CellType type);
    void drawEdge(GameWindow *gameWindow, const sf::Color &color);
    void drawRailroadName(GameWindow *gameWindow, const sf::Color &color);
    void drawPrice(GameWindow *gameWindow, const sf::Color &color);
    void drawStreetGroup(GameWindow *gameWindow);
    void drawStreetName(GameWindow *gameWindow, const sf::Color &color);
    void drawPossessionStatus(GameWindow *gameWindow);

};

#endif // __GAMECELL__

