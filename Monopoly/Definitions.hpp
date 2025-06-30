#ifndef __DEFINITIONS__
#define __DEFINITIONS__

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#define NOTAVAILABLEVALUE -1
#define MAXPLAYERS 8

#define GAMECELL_OUTLINESIZE 1

#define GAMEDEFINITION_BROWN sf::Color(165,42,42,255)
#define GAMEDEFINITION_SKYBLUE sf::Color(135,206,235,255)
#define GAMEDEFINITION_PURPLE sf::Color(160,32,240,255)
#define GAMEDEFINITION_ORANGE sf::Color(255,165,0,255)

#define GAMECELL_BACKGROUNDCOLOR sf::Color(48,48,48,255)
#define GAMECELL_EDGECOLOR sf::Color(0,0,0,255)

#define GAMERULE_WINNERBALANCE 4000

enum class CellType {Undefined, Start, Street, RailRoad, Chance, Chest, FreeParking, Tax, GotoJail, Jail, Company};
enum class StreetGroup {Undefined, Brown, SkyBlue, Purple, Orange, Red, Yellow, Green, Blue};
enum class CellPosition {Undefined, Up, Down, Left, Right, Center};
enum class GameState {Undefined, NotEnoughPlayer, ReadyToStart, ManageAssetsOrRollDice, ManageAssetsOrNextPlayer, WaitForChanceValue, WaitForChestValue, NegativeBalance, Bankrupt, GameOver };
enum class GameAction {Undefined, UsePardonCard, PayAFine, BuyProperty, SellProperty, UpgradeProperty, DowngradeProperty};

class Helper {

public:

    static std::string getMoneyString(int money) { return std::to_string(money) + " ILS"; }

};

class GameCell;
class Player;
class GameBoard;
class GameWindow;

#endif // __DEFINITIONS__
