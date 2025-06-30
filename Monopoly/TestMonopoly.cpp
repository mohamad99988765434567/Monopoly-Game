#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <SFML/Graphics.hpp>

#include "Definitions.hpp"
#include "GameCell.hpp"
#include "GameBoard.hpp"

// Note: These tests performed on a game board has the same layout as the game board of the Monopoly.cpp
// Please refer to the game UI to get clear view about these test cases

TEST_CASE("Test: Adding Spaces for Gameboard") {
    GameBoard gameBoard;
    gameBoard.appendCell(GameCell::makeFreeParkingCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Kentucky", 220));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Up));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Indiana", 220));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Illinois", 240));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Up, "B & O", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Atantic", 260));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Ventnor", 260));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Up, "Water Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Marvin", 280));
    gameBoard.appendCell(GameCell::makeGotoJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pacific", 300));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Carolina", 300));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pennsylvania", 320));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Right, "Short Line", 200));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Broadwalk", 350));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Park Place", 400));
    gameBoard.appendCell(GameCell::makeStartCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Black Sea", 60));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Baltic", 60));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Down, "Reading", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Oriental", 100));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Vermont", 100));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Connecticut", 120));
    gameBoard.appendCell(GameCell::makeJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "St. Charles", 140));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Left, "Electric Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "States", 140));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "Virginia", 160));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Left, "Pennsylvania", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "St. James", 180));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Left));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "Tennessee", 180));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "New York", 200));

    CHECK(gameBoard.cells.size() == 40); // explanation: game board must have 40 spaces now
}

TEST_CASE("Test: Adding 8 players") {
    GameBoard gameBoard;
    gameBoard.appendCell(GameCell::makeFreeParkingCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Kentucky", 220));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Up));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Indiana", 220));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Illinois", 240));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Up, "B & O", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Atantic", 260));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Ventnor", 260));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Up, "Water Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Marvin", 280));
    gameBoard.appendCell(GameCell::makeGotoJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pacific", 300));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Carolina", 300));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pennsylvania", 320));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Right, "Short Line", 200));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Broadwalk", 350));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Park Place", 400));
    gameBoard.appendCell(GameCell::makeStartCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Black Sea", 60));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Baltic", 60));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Down, "Reading", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Oriental", 100));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Vermont", 100));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Connecticut", 120));
    gameBoard.appendCell(GameCell::makeJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "St. Charles", 140));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Left, "Electric Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "States", 140));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "Virginia", 160));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Left, "Pennsylvania", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "St. James", 180));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Left));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "Tennessee", 180));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "New York", 200));

    for (int i=0; i<8; i++) {
        gameBoard.appendPlayer(Player::makePlayer("Player " + std::to_string(i+1), 1500, 20));
    }

    CHECK(gameBoard.cells.size() == 40);
    CHECK(gameBoard.players.size() == 8); // explanation: there must be 8 players on game board now
}

TEST_CASE("Test: Start Game") {
    GameBoard gameBoard;
    gameBoard.appendCell(GameCell::makeFreeParkingCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Kentucky", 220));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Up));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Indiana", 220));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Illinois", 240));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Up, "B & O", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Atantic", 260));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Ventnor", 260));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Up, "Water Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Marvin", 280));
    gameBoard.appendCell(GameCell::makeGotoJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pacific", 300));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Carolina", 300));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pennsylvania", 320));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Right, "Short Line", 200));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Broadwalk", 350));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Park Place", 400));
    gameBoard.appendCell(GameCell::makeStartCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Black Sea", 60));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Baltic", 60));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Down, "Reading", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Oriental", 100));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Vermont", 100));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Connecticut", 120));
    gameBoard.appendCell(GameCell::makeJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "St. Charles", 140));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Left, "Electric Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "States", 140));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "Virginia", 160));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Left, "Pennsylvania", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "St. James", 180));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Left));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "Tennessee", 180));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "New York", 200));

    for (int i=0; i<8; i++) {
        gameBoard.appendPlayer(Player::makePlayer("Player " + std::to_string(i+1), 1500, 20));
    }

    gameBoard.startGame();

    CHECK(gameBoard.cells.size() == 40);
    CHECK(gameBoard.players.size() == 8);
    CHECK(gameBoard.getActivePlayerId() == 0); // explanation: the game started
}

TEST_CASE("Test: Make a move") {
    GameBoard gameBoard;
    gameBoard.appendCell(GameCell::makeFreeParkingCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Kentucky", 220));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Up));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Indiana", 220));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Illinois", 240));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Up, "B & O", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Atantic", 260));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Ventnor", 260));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Up, "Water Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Marvin", 280));
    gameBoard.appendCell(GameCell::makeGotoJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pacific", 300));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Carolina", 300));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pennsylvania", 320));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Right, "Short Line", 200));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Broadwalk", 350));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Park Place", 400));
    gameBoard.appendCell(GameCell::makeStartCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Black Sea", 60));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Baltic", 60));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Down, "Reading", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Oriental", 100));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Vermont", 100));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Connecticut", 120));
    gameBoard.appendCell(GameCell::makeJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "St. Charles", 140));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Left, "Electric Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "States", 140));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "Virginia", 160));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Left, "Pennsylvania", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "St. James", 180));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Left));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "Tennessee", 180));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "New York", 200));

    for (int i=0; i<2; i++) {
        gameBoard.appendPlayer(Player::makePlayer("Player " + std::to_string(i+1), 1500, 20));
    }

    gameBoard.startGame();
    
    CHECK(gameBoard.cells.size() == 40);
    CHECK(gameBoard.players.size() == 2);
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getGameState() == GameState::ManageAssetsOrRollDice); // explanation: GameState that allows player to roll dice
    CHECK(gameBoard.getActivePlayer()->cellIndex == 20); // explanation: index of Start Space is 20
    gameBoard.pushDice(6, 6); // explanation: put dice
    CHECK(gameBoard.getActivePlayer()->cellIndex == 32); // // explanation: player must be moved on the board
}

TEST_CASE("Test: Move 2 players in turn") {
    GameBoard gameBoard;
    gameBoard.appendCell(GameCell::makeFreeParkingCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Kentucky", 220));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Up));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Indiana", 220));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Illinois", 240));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Up, "B & O", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Atantic", 260));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Ventnor", 260));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Up, "Water Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Marvin", 280));
    gameBoard.appendCell(GameCell::makeGotoJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pacific", 300));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Carolina", 300));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pennsylvania", 320));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Right, "Short Line", 200));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Broadwalk", 350));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Park Place", 400));
    gameBoard.appendCell(GameCell::makeStartCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Black Sea", 60));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Baltic", 60));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Down, "Reading", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Oriental", 100));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Vermont", 100));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Connecticut", 120));
    gameBoard.appendCell(GameCell::makeJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "St. Charles", 140));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Left, "Electric Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "States", 140));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "Virginia", 160));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Left, "Pennsylvania", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "St. James", 180));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Left));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "Tennessee", 180));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "New York", 200));

    for (int i=0; i<2; i++) {
        gameBoard.appendPlayer(Player::makePlayer("Player " + std::to_string(i+1), 1500, 20));
    }

    gameBoard.startGame();
    
    CHECK(gameBoard.cells.size() == 40);
    CHECK(gameBoard.players.size() == 2);
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getGameState() == GameState::ManageAssetsOrRollDice); // explanation: GameState that allows player to roll dice
    CHECK(gameBoard.getActivePlayer()->cellIndex == 20); // explanation: index of Start Space is 20
    gameBoard.pushDice(4, 5); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 29); // explanation: player 1 moved on the board
    gameBoard.nextPlayer(); // explanation: next turn
    gameBoard.pushDice(3, 5); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 1);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 28); // explanation: player 2 moved on the board
    gameBoard.nextPlayer(); // explanation: next turn
    gameBoard.pushDice(5, 6); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 0); // explanation: player 1 moved on the board
}

TEST_CASE("Test: A player roll Double and get additional turn") {
    GameBoard gameBoard;
    gameBoard.appendCell(GameCell::makeFreeParkingCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Kentucky", 220));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Up));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Indiana", 220));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Illinois", 240));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Up, "B & O", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Atantic", 260));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Ventnor", 260));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Up, "Water Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Marvin", 280));
    gameBoard.appendCell(GameCell::makeGotoJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pacific", 300));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Carolina", 300));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pennsylvania", 320));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Right, "Short Line", 200));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Broadwalk", 350));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Park Place", 400));
    gameBoard.appendCell(GameCell::makeStartCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Black Sea", 60));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Baltic", 60));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Down, "Reading", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Oriental", 100));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Vermont", 100));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Connecticut", 120));
    gameBoard.appendCell(GameCell::makeJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "St. Charles", 140));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Left, "Electric Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "States", 140));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "Virginia", 160));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Left, "Pennsylvania", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "St. James", 180));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Left));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "Tennessee", 180));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "New York", 200));

    for (int i=0; i<2; i++) {
        gameBoard.appendPlayer(Player::makePlayer("Player " + std::to_string(i+1), 1500, 20));
    }

    gameBoard.startGame();
    
    CHECK(gameBoard.cells.size() == 40);
    CHECK(gameBoard.players.size() == 2);
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getGameState() == GameState::ManageAssetsOrRollDice); // explanation: GameState that allows player to roll dice
    CHECK(gameBoard.getActivePlayer()->cellIndex == 20); // explanation: index of Start Space is 20
    gameBoard.pushDice(4, 4); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 28); // explanation: player 1 moved on the board
    gameBoard.nextPlayer(); // explanation: next turn - it's must be failed, and player 1 still keeps his turn
    gameBoard.pushDice(3, 5); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 36); // explanation: player 1 moved on the board
    gameBoard.nextPlayer(); // explanation: next turn, player 2 gets his turn
    gameBoard.pushDice(5, 6); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 1);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 31); // explanation: player 2 moved on the board
}

TEST_CASE("Test: A player roll 3 continuous Doubles and got jailed") {
    GameBoard gameBoard;
    gameBoard.appendCell(GameCell::makeFreeParkingCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Kentucky", 220));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Up));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Indiana", 220));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Illinois", 240));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Up, "B & O", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Atantic", 260));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Ventnor", 260));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Up, "Water Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Marvin", 280));
    gameBoard.appendCell(GameCell::makeGotoJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pacific", 300));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Carolina", 300));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pennsylvania", 320));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Right, "Short Line", 200));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Broadwalk", 350));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Park Place", 400));
    gameBoard.appendCell(GameCell::makeStartCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Black Sea", 60));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Baltic", 60));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Down, "Reading", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Oriental", 100));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Vermont", 100));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Connecticut", 120));
    gameBoard.appendCell(GameCell::makeJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "St. Charles", 140));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Left, "Electric Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "States", 140));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "Virginia", 160));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Left, "Pennsylvania", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "St. James", 180));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Left));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "Tennessee", 180));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "New York", 200));

    for (int i=0; i<2; i++) {
        gameBoard.appendPlayer(Player::makePlayer("Player " + std::to_string(i+1), 1500, 20));
    }

    gameBoard.startGame();
    
    CHECK(gameBoard.cells.size() == 40);
    CHECK(gameBoard.players.size() == 2);
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getGameState() == GameState::ManageAssetsOrRollDice); // explanation: GameState that allows player to roll dice
    CHECK(gameBoard.getActivePlayer()->cellIndex == 20); // explanation: index of Start Space is 20
    gameBoard.pushDice(4, 4); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 28); // explanation: player 1 moved on the board
    gameBoard.nextPlayer(); // explanation: next turn - it's must be failed, and player 1 still keeps his turn
    gameBoard.pushDice(2, 2); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 32); // explanation: player 1 moved on the board
    gameBoard.nextPlayer(); // explanation: next turn - it's must be failed, and player 1 still keeps his turn
    gameBoard.pushDice(3, 3); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 30); // explanation: Jail is the #30 space
    CHECK(gameBoard.getActivePlayer()->isJailed == true); // explanation: Player 1 must be jailed
}

TEST_CASE("Test: Player buy a street") {
    GameBoard gameBoard;
    gameBoard.appendCell(GameCell::makeFreeParkingCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Kentucky", 220));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Up));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Indiana", 220));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Illinois", 240));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Up, "B & O", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Atantic", 260));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Ventnor", 260));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Up, "Water Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Marvin", 280));
    gameBoard.appendCell(GameCell::makeGotoJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pacific", 300));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Carolina", 300));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pennsylvania", 320));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Right, "Short Line", 200));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Broadwalk", 350));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Park Place", 400));
    gameBoard.appendCell(GameCell::makeStartCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Black Sea", 60));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Baltic", 60));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Down, "Reading", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Oriental", 100));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Vermont", 100));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Connecticut", 120));
    gameBoard.appendCell(GameCell::makeJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "St. Charles", 140));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Left, "Electric Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "States", 140));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "Virginia", 160));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Left, "Pennsylvania", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "St. James", 180));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Left));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "Tennessee", 180));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "New York", 200));

    for (int i=0; i<2; i++) {
        gameBoard.appendPlayer(Player::makePlayer("Player " + std::to_string(i+1), 1500, 20));
    }

    gameBoard.startGame();
    
    CHECK(gameBoard.cells.size() == 40);
    CHECK(gameBoard.players.size() == 2);
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getGameState() == GameState::ManageAssetsOrRollDice); // explanation: GameState that allows player to roll dice
    CHECK(gameBoard.getActivePlayer()->cellIndex == 20); // explanation: index of Start Space is 20
    gameBoard.pushDice(4, 5); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 29); // explanation: player 1 moved to Connecticut Avenue
    gameBoard.updateActivePlayerAssets(); // explanation: list his assets
    CHECK(gameBoard.getActivePlayerCellCounter() == 0);  // explanation: he must have 0 cell (property) at the start
    gameBoard.pushAction(GameAction::BuyProperty, 29); // explanation: player 1 buys Connecticut Avenue (space #29)
    gameBoard.updateActivePlayerAssets(); // explanation: list his assets
    CHECK(gameBoard.getActivePlayerCellCounter() == 1);  // explanation: he must have 1 cell (property) now
    CHECK(gameBoard.getActivePlayer()->balance == 1380); // explanation: player 1 has $1380 now (he paid $120 to buy Connecticut Avenue)
}

TEST_CASE("Test: Player 2 rents a street that player 1 has bought") {
    GameBoard gameBoard;
    gameBoard.appendCell(GameCell::makeFreeParkingCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Kentucky", 220));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Up));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Indiana", 220));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Illinois", 240));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Up, "B & O", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Atantic", 260));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Ventnor", 260));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Up, "Water Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Marvin", 280));
    gameBoard.appendCell(GameCell::makeGotoJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pacific", 300));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Carolina", 300));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pennsylvania", 320));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Right, "Short Line", 200));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Broadwalk", 350));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Park Place", 400));
    gameBoard.appendCell(GameCell::makeStartCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Black Sea", 60));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Baltic", 60));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Down, "Reading", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Oriental", 100));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Vermont", 100));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Connecticut", 120));
    gameBoard.appendCell(GameCell::makeJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "St. Charles", 140));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Left, "Electric Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "States", 140));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "Virginia", 160));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Left, "Pennsylvania", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "St. James", 180));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Left));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "Tennessee", 180));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "New York", 200));

    for (int i=0; i<2; i++) {
        gameBoard.appendPlayer(Player::makePlayer("Player " + std::to_string(i+1), 1500, 20));
    }

    gameBoard.startGame();
    
    CHECK(gameBoard.cells.size() == 40);
    CHECK(gameBoard.players.size() == 2);
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getGameState() == GameState::ManageAssetsOrRollDice); // explanation: GameState that allows player to roll dice
    CHECK(gameBoard.getActivePlayer()->cellIndex == 20); // explanation: index of Start Space is 20
    gameBoard.pushDice(4, 5); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 29); // explanation: player 1 moved to Connecticut Avenue
    gameBoard.updateActivePlayerAssets(); // explanation: list his assets
    CHECK(gameBoard.getActivePlayerCellCounter() == 0);  // explanation: he must have 0 cell (property) at the start
    gameBoard.pushAction(GameAction::BuyProperty, 29); // explanation: player 1 buys Connecticut Avenue (space #29)
    gameBoard.updateActivePlayerAssets(); // explanation: list his assets
    CHECK(gameBoard.getActivePlayerCellCounter() == 1);  // explanation: he must have 1 cell (property) now
    CHECK(gameBoard.getActivePlayer()->balance == 1380); // explanation: player 1 has $1380 now (he paid $120 to buy Connecticut Avenue)
    gameBoard.nextPlayer(); // explanation: next turn, player 2
    CHECK(gameBoard.getActivePlayerId() == 1);
    CHECK(gameBoard.getActivePlayer()->balance == 1500); // explanation: initial balance of player 2
    gameBoard.pushDice(4, 5); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 1);
    CHECK(gameBoard.getActivePlayer()->balance == 1488); // explanation: player 2 paid $12
    gameBoard.nextPlayer(); // explanation: next turn, player 1
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->balance == 1392); // explanation: player 1 got $12 from player 2
}

TEST_CASE("Test: Player 2 can't buy a street that player 1 has bought") {
    GameBoard gameBoard;
    gameBoard.appendCell(GameCell::makeFreeParkingCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Kentucky", 220));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Up));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Indiana", 220));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Illinois", 240));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Up, "B & O", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Atantic", 260));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Ventnor", 260));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Up, "Water Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Marvin", 280));
    gameBoard.appendCell(GameCell::makeGotoJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pacific", 300));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Carolina", 300));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pennsylvania", 320));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Right, "Short Line", 200));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Broadwalk", 350));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Park Place", 400));
    gameBoard.appendCell(GameCell::makeStartCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Black Sea", 60));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Baltic", 60));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Down, "Reading", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Oriental", 100));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Vermont", 100));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Connecticut", 120));
    gameBoard.appendCell(GameCell::makeJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "St. Charles", 140));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Left, "Electric Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "States", 140));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "Virginia", 160));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Left, "Pennsylvania", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "St. James", 180));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Left));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "Tennessee", 180));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "New York", 200));

    for (int i=0; i<2; i++) {
        gameBoard.appendPlayer(Player::makePlayer("Player " + std::to_string(i+1), 1500, 20));
    }

    gameBoard.startGame();
    
    CHECK(gameBoard.cells.size() == 40);
    CHECK(gameBoard.players.size() == 2);
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getGameState() == GameState::ManageAssetsOrRollDice); // explanation: GameState that allows player to roll dice
    CHECK(gameBoard.getActivePlayer()->cellIndex == 20); // explanation: index of Start Space is 20
    gameBoard.pushDice(4, 5); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 29); // explanation: player 1 moved to Connecticut Avenue
    gameBoard.updateActivePlayerAssets(); // explanation: list his assets
    CHECK(gameBoard.getActivePlayerCellCounter() == 0);  // explanation: he must have 0 cell (property) at the start
    gameBoard.pushAction(GameAction::BuyProperty, 29); // explanation: player 1 buys Connecticut Avenue (space #29)
    gameBoard.updateActivePlayerAssets(); // explanation: list his assets
    CHECK(gameBoard.getActivePlayerCellCounter() == 1);  // explanation: he must have 1 cell (property) now
    CHECK(gameBoard.getActivePlayer()->balance == 1380); // explanation: player 1 has $1380 now (he paid $120 to buy Connecticut Avenue)
    gameBoard.nextPlayer(); // explanation: next turn, player 2
    CHECK(gameBoard.getActivePlayerId() == 1);
    CHECK(gameBoard.getActivePlayer()->balance == 1500); // explanation: initial balance of player 2
    gameBoard.pushDice(4, 5); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 1);
    CHECK(gameBoard.getActivePlayer()->balance == 1488); // explanation: player 2 paid $12
    gameBoard.pushAction(GameAction::BuyProperty, 29); // explanation: player 2 tries to buy Connecticut Avenue (space #29)
    gameBoard.updateActivePlayerAssets(); // explanation: list his assets
    CHECK(gameBoard.getActivePlayerCellCounter() == 0);  // explanation: he must have 0 cell (property) now
    CHECK(gameBoard.getActivePlayer()->balance == 1488); // explanation: no money charged
}

TEST_CASE("Test: Players pay tax when they stop at the tax space") {
    GameBoard gameBoard;
    gameBoard.appendCell(GameCell::makeFreeParkingCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Kentucky", 220));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Up));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Indiana", 220));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Illinois", 240));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Up, "B & O", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Atantic", 260));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Ventnor", 260));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Up, "Water Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Marvin", 280));
    gameBoard.appendCell(GameCell::makeGotoJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pacific", 300));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Carolina", 300));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pennsylvania", 320));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Right, "Short Line", 200));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Broadwalk", 350));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Park Place", 400));
    gameBoard.appendCell(GameCell::makeStartCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Black Sea", 60));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Baltic", 60));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Down, "Reading", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Oriental", 100));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Vermont", 100));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Connecticut", 120));
    gameBoard.appendCell(GameCell::makeJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "St. Charles", 140));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Left, "Electric Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "States", 140));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "Virginia", 160));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Left, "Pennsylvania", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "St. James", 180));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Left));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "Tennessee", 180));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "New York", 200));

    for (int i=0; i<2; i++) {
        gameBoard.appendPlayer(Player::makePlayer("Player " + std::to_string(i+1), 1500, 20));
    }

    gameBoard.startGame();
    
    CHECK(gameBoard.cells.size() == 40);
    CHECK(gameBoard.players.size() == 2);
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getGameState() == GameState::ManageAssetsOrRollDice); // explanation: GameState that allows player to roll dice
    CHECK(gameBoard.getActivePlayer()->cellIndex == 20); // explanation: index of Start Space is 20
    CHECK(gameBoard.getActivePlayer()->balance == 1500); // explanation: initial balance of player 1
    gameBoard.pushDice(2, 2); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 24); // explanation: player 1 moved to #24, it's a Tax space
    CHECK(gameBoard.getActivePlayer()->balance == 1400); // explanation: Player 1 paid $100 for Tax
}

TEST_CASE("Test: Player stops at Chance space - Advance to Go and get $200") {
    GameBoard gameBoard;
    gameBoard.appendCell(GameCell::makeFreeParkingCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Kentucky", 220));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Up));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Indiana", 220));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Illinois", 240));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Up, "B & O", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Atantic", 260));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Ventnor", 260));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Up, "Water Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Marvin", 280));
    gameBoard.appendCell(GameCell::makeGotoJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pacific", 300));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Carolina", 300));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pennsylvania", 320));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Right, "Short Line", 200));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Broadwalk", 350));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Park Place", 400));
    gameBoard.appendCell(GameCell::makeStartCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Black Sea", 60));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Baltic", 60));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Down, "Reading", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Oriental", 100));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Vermont", 100));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Connecticut", 120));
    gameBoard.appendCell(GameCell::makeJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "St. Charles", 140));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Left, "Electric Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "States", 140));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "Virginia", 160));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Left, "Pennsylvania", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "St. James", 180));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Left));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "Tennessee", 180));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "New York", 200));

    for (int i=0; i<2; i++) {
        gameBoard.appendPlayer(Player::makePlayer("Player " + std::to_string(i+1), 1500, 20));
    }

    gameBoard.startGame();
    
    CHECK(gameBoard.cells.size() == 40);
    CHECK(gameBoard.players.size() == 2);
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getGameState() == GameState::ManageAssetsOrRollDice); // explanation: GameState that allows player to roll dice
    CHECK(gameBoard.getActivePlayer()->cellIndex == 20); // explanation: index of Start Space is 20
    CHECK(gameBoard.getActivePlayer()->balance == 1500); // explanation: initial balance of player 1
    gameBoard.pushDice(2, 5); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 27); // explanation: player 1 moved to #27, it's a Chance space
    gameBoard.pushChanceValue(0); // explanation: Chance == Advance to Go and get $200
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->balance == 1700); // explanation: He got $200
    CHECK(gameBoard.getActivePlayer()->cellIndex == 20); // explanation: He advanced to go
}

TEST_CASE("Test: Player stops at Chance space - Go back 3 spaces") {
    GameBoard gameBoard;
    gameBoard.appendCell(GameCell::makeFreeParkingCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Kentucky", 220));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Up));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Indiana", 220));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Illinois", 240));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Up, "B & O", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Atantic", 260));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Ventnor", 260));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Up, "Water Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Marvin", 280));
    gameBoard.appendCell(GameCell::makeGotoJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pacific", 300));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Carolina", 300));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pennsylvania", 320));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Right, "Short Line", 200));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Broadwalk", 350));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Park Place", 400));
    gameBoard.appendCell(GameCell::makeStartCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Black Sea", 60));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Baltic", 60));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Down, "Reading", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Oriental", 100));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Vermont", 100));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Connecticut", 120));
    gameBoard.appendCell(GameCell::makeJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "St. Charles", 140));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Left, "Electric Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "States", 140));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "Virginia", 160));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Left, "Pennsylvania", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "St. James", 180));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Left));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "Tennessee", 180));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "New York", 200));

    for (int i=0; i<2; i++) {
        gameBoard.appendPlayer(Player::makePlayer("Player " + std::to_string(i+1), 1500, 20));
    }

    gameBoard.startGame();
    
    CHECK(gameBoard.cells.size() == 40);
    CHECK(gameBoard.players.size() == 2);
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getGameState() == GameState::ManageAssetsOrRollDice); // explanation: GameState that allows player to roll dice
    CHECK(gameBoard.getActivePlayer()->cellIndex == 20); // explanation: index of Start Space is 20
    CHECK(gameBoard.getActivePlayer()->balance == 1500); // explanation: initial balance of player 1
    gameBoard.pushDice(2, 5); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 27); // explanation: player 1 moved to #27, it's a Chance space
    gameBoard.pushChanceValue(2); // explanation: Chance == Go back 3 spaces
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 24); // explanation: Go back 3 spaces
}

TEST_CASE("Test: Player stops at Chance space - Go directly to Jail – do not pass Go, do not collect $200") {
    GameBoard gameBoard;
    gameBoard.appendCell(GameCell::makeFreeParkingCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Kentucky", 220));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Up));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Indiana", 220));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Illinois", 240));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Up, "B & O", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Atantic", 260));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Ventnor", 260));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Up, "Water Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Marvin", 280));
    gameBoard.appendCell(GameCell::makeGotoJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pacific", 300));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Carolina", 300));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pennsylvania", 320));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Right, "Short Line", 200));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Broadwalk", 350));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Park Place", 400));
    gameBoard.appendCell(GameCell::makeStartCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Black Sea", 60));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Baltic", 60));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Down, "Reading", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Oriental", 100));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Vermont", 100));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Connecticut", 120));
    gameBoard.appendCell(GameCell::makeJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "St. Charles", 140));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Left, "Electric Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "States", 140));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "Virginia", 160));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Left, "Pennsylvania", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "St. James", 180));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Left));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "Tennessee", 180));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "New York", 200));

    for (int i=0; i<2; i++) {
        gameBoard.appendPlayer(Player::makePlayer("Player " + std::to_string(i+1), 1500, 20));
    }

    gameBoard.startGame();
    
    CHECK(gameBoard.cells.size() == 40);
    CHECK(gameBoard.players.size() == 2);
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getGameState() == GameState::ManageAssetsOrRollDice); // explanation: GameState that allows player to roll dice
    CHECK(gameBoard.getActivePlayer()->cellIndex == 20); // explanation: index of Start Space is 20
    CHECK(gameBoard.getActivePlayer()->balance == 1500); // explanation: initial balance of player 1
    gameBoard.pushDice(2, 5); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 27); // explanation: player 1 moved to #27, it's a Chance space
    gameBoard.pushChanceValue(3); // explanation: Chance == Go directly to Jail – do not pass Go, do not collect $200
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 30); // explanation: Go directly to Jail – do not pass Go, do not collect $200
    CHECK(gameBoard.getActivePlayer()->isJailed == true);
    CHECK(gameBoard.getActivePlayer()->balance == 1500); // explanation: still $1500
}

TEST_CASE("Test: Player stops at Chance space - Take a trip to Reading Railroad, pass Go and collect $200") {
    GameBoard gameBoard;
    gameBoard.appendCell(GameCell::makeFreeParkingCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Kentucky", 220));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Up));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Indiana", 220));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Illinois", 240));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Up, "B & O", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Atantic", 260));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Ventnor", 260));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Up, "Water Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Marvin", 280));
    gameBoard.appendCell(GameCell::makeGotoJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pacific", 300));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Carolina", 300));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pennsylvania", 320));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Right, "Short Line", 200));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Broadwalk", 350));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Park Place", 400));
    gameBoard.appendCell(GameCell::makeStartCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Black Sea", 60));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Baltic", 60));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Down, "Reading", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Oriental", 100));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Vermont", 100));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Connecticut", 120));
    gameBoard.appendCell(GameCell::makeJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "St. Charles", 140));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Left, "Electric Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "States", 140));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "Virginia", 160));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Left, "Pennsylvania", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "St. James", 180));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Left));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "Tennessee", 180));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "New York", 200));

    for (int i=0; i<2; i++) {
        gameBoard.appendPlayer(Player::makePlayer("Player " + std::to_string(i+1), 1500, 20));
    }

    gameBoard.startGame();
    
    CHECK(gameBoard.cells.size() == 40);
    CHECK(gameBoard.players.size() == 2);
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getGameState() == GameState::ManageAssetsOrRollDice); // explanation: GameState that allows player to roll dice
    CHECK(gameBoard.getActivePlayer()->cellIndex == 20); // explanation: index of Start Space is 20
    CHECK(gameBoard.getActivePlayer()->balance == 1500); // explanation: initial balance of player 1
    gameBoard.pushDice(2, 5); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 27); // explanation: player 1 moved to #27, it's a Chance space
    gameBoard.pushChanceValue(6); // explanation: Take a trip to Reading Railroad, pass Go and collect $200
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 25); // Take a trip to Reading Railroad, pass Go and collect $200
    CHECK(gameBoard.getActivePlayer()->balance == 1700); // explanation: got $200
}

TEST_CASE("Test: Player stops at Chance space - elected Chairman of the Board Pay each player $50") {
    GameBoard gameBoard;
    gameBoard.appendCell(GameCell::makeFreeParkingCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Kentucky", 220));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Up));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Indiana", 220));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Illinois", 240));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Up, "B & O", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Atantic", 260));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Ventnor", 260));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Up, "Water Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Marvin", 280));
    gameBoard.appendCell(GameCell::makeGotoJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pacific", 300));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Carolina", 300));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pennsylvania", 320));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Right, "Short Line", 200));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Broadwalk", 350));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Park Place", 400));
    gameBoard.appendCell(GameCell::makeStartCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Black Sea", 60));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Baltic", 60));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Down, "Reading", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Oriental", 100));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Vermont", 100));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Connecticut", 120));
    gameBoard.appendCell(GameCell::makeJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "St. Charles", 140));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Left, "Electric Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "States", 140));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "Virginia", 160));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Left, "Pennsylvania", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "St. James", 180));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Left));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "Tennessee", 180));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "New York", 200));

    for (int i=0; i<8; i++) {
        gameBoard.appendPlayer(Player::makePlayer("Player " + std::to_string(i+1), 1500, 20));
    }

    gameBoard.startGame();
    
    CHECK(gameBoard.cells.size() == 40);
    CHECK(gameBoard.players.size() == 8);
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getGameState() == GameState::ManageAssetsOrRollDice); // explanation: GameState that allows player to roll dice
    CHECK(gameBoard.getActivePlayer()->cellIndex == 20); // explanation: index of Start Space is 20
    CHECK(gameBoard.getActivePlayer()->balance == 1500); // explanation: initial balance of player 1
    gameBoard.pushDice(2, 5); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 27); // explanation: player 1 moved to #27, it's a Chance space
    gameBoard.pushChanceValue(8); // explanation: elected Chairman of the Board – Pay each player $50
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->balance == 1150); // explanation: lost $50 x 7 players
    gameBoard.nextPlayer();
    CHECK(gameBoard.getActivePlayerId() == 1);
    CHECK(gameBoard.getActivePlayer()->balance == 1550); // explanation: other players get $50
}

TEST_CASE("Test: Player stops at Chance space - Advance to nearest Utility") {
    GameBoard gameBoard;
    gameBoard.appendCell(GameCell::makeFreeParkingCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Kentucky", 220));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Up));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Indiana", 220));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Illinois", 240));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Up, "B & O", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Atantic", 260));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Ventnor", 260));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Up, "Water Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Marvin", 280));
    gameBoard.appendCell(GameCell::makeGotoJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pacific", 300));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Carolina", 300));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pennsylvania", 320));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Right, "Short Line", 200));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Broadwalk", 350));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Park Place", 400));
    gameBoard.appendCell(GameCell::makeStartCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Black Sea", 60));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Baltic", 60));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Down, "Reading", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Oriental", 100));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Vermont", 100));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Connecticut", 120));
    gameBoard.appendCell(GameCell::makeJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "St. Charles", 140));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Left, "Electric Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "States", 140));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "Virginia", 160));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Left, "Pennsylvania", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "St. James", 180));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Left));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "Tennessee", 180));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "New York", 200));

    for (int i=0; i<8; i++) {
        gameBoard.appendPlayer(Player::makePlayer("Player " + std::to_string(i+1), 1500, 20));
    }

    gameBoard.startGame();
    
    CHECK(gameBoard.cells.size() == 40);
    CHECK(gameBoard.players.size() == 8);
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getGameState() == GameState::ManageAssetsOrRollDice); // explanation: GameState that allows player to roll dice
    CHECK(gameBoard.getActivePlayer()->cellIndex == 20); // explanation: index of Start Space is 20
    CHECK(gameBoard.getActivePlayer()->balance == 1500); // explanation: initial balance of player 1
    gameBoard.pushDice(2, 5); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 27); // explanation: player 1 moved to #27, it's a Chance space
    gameBoard.pushChanceValue(14); // explanation: Advance to nearest Utility
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 32); // explanation: nearest utilities is Electric Company at #32
}

TEST_CASE("Test: Player stops at Chance space - Get a Pardon Card (Get out of Jail free)") {
    GameBoard gameBoard;
    gameBoard.appendCell(GameCell::makeFreeParkingCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Kentucky", 220));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Up));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Indiana", 220));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Illinois", 240));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Up, "B & O", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Atantic", 260));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Ventnor", 260));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Up, "Water Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Marvin", 280));
    gameBoard.appendCell(GameCell::makeGotoJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pacific", 300));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Carolina", 300));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pennsylvania", 320));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Right, "Short Line", 200));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Broadwalk", 350));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Park Place", 400));
    gameBoard.appendCell(GameCell::makeStartCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Black Sea", 60));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Baltic", 60));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Down, "Reading", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Oriental", 100));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Vermont", 100));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Connecticut", 120));
    gameBoard.appendCell(GameCell::makeJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "St. Charles", 140));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Left, "Electric Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "States", 140));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "Virginia", 160));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Left, "Pennsylvania", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "St. James", 180));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Left));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "Tennessee", 180));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "New York", 200));

    for (int i=0; i<8; i++) {
        gameBoard.appendPlayer(Player::makePlayer("Player " + std::to_string(i+1), 1500, 20));
    }

    gameBoard.startGame();
    
    CHECK(gameBoard.cells.size() == 40);
    CHECK(gameBoard.players.size() == 8);
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getGameState() == GameState::ManageAssetsOrRollDice); // explanation: GameState that allows player to roll dice
    CHECK(gameBoard.getActivePlayer()->cellIndex == 20); // explanation: index of Start Space is 20
    CHECK(gameBoard.getActivePlayer()->balance == 1500); // explanation: initial balance of player 1
    CHECK(gameBoard.getActivePlayer()->pardonCardCounter == 0); // explanation: he has 0 Pardon Card at start
    gameBoard.pushDice(2, 5); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 27); // explanation: player 1 moved to #27, it's a Chance space
    gameBoard.pushChanceValue(10); // explanation: Advance to nearest Utility
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->pardonCardCounter == 1); // explanation: He has 1 Pardon Card now
}

TEST_CASE("Test: Player stops at the Jail as Visitor, he is not jailed") {
    GameBoard gameBoard;
    gameBoard.appendCell(GameCell::makeFreeParkingCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Kentucky", 220));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Up));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Indiana", 220));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Illinois", 240));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Up, "B & O", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Atantic", 260));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Ventnor", 260));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Up, "Water Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Marvin", 280));
    gameBoard.appendCell(GameCell::makeGotoJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pacific", 300));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Carolina", 300));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pennsylvania", 320));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Right, "Short Line", 200));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Broadwalk", 350));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Park Place", 400));
    gameBoard.appendCell(GameCell::makeStartCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Black Sea", 60));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Baltic", 60));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Down, "Reading", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Oriental", 100));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Vermont", 100));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Connecticut", 120));
    gameBoard.appendCell(GameCell::makeJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "St. Charles", 140));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Left, "Electric Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "States", 140));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "Virginia", 160));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Left, "Pennsylvania", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "St. James", 180));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Left));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "Tennessee", 180));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "New York", 200));

    for (int i=0; i<8; i++) {
        gameBoard.appendPlayer(Player::makePlayer("Player " + std::to_string(i+1), 1500, 20));
    }

    gameBoard.startGame();
    
    CHECK(gameBoard.cells.size() == 40);
    CHECK(gameBoard.players.size() == 8);
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getGameState() == GameState::ManageAssetsOrRollDice); // explanation: GameState that allows player to roll dice
    CHECK(gameBoard.getActivePlayer()->cellIndex == 20); // explanation: index of Start Space is 20
    CHECK(gameBoard.getActivePlayer()->balance == 1500); // explanation: initial balance of player 1
    gameBoard.pushDice(6, 4); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 30); // explanation: player 1 moved to #30, it's the Jail
    CHECK(gameBoard.getActivePlayer()->isJailed == false); // explanation: player 1 is not jailed
}

TEST_CASE("Test: Player 2 has $0, he jumps onto a street owned by Player 1, player 2 has no money to pay the fee, he goes bankrupt, game is over, player 1 is the winner") {
    GameBoard gameBoard;
    gameBoard.appendCell(GameCell::makeFreeParkingCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Kentucky", 220));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Up));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Indiana", 220));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Illinois", 240));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Up, "B & O", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Atantic", 260));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Ventnor", 260));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Up, "Water Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Marvin", 280));
    gameBoard.appendCell(GameCell::makeGotoJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pacific", 300));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Carolina", 300));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pennsylvania", 320));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Right, "Short Line", 200));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Broadwalk", 350));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Right));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Park Place", 400));
    gameBoard.appendCell(GameCell::makeStartCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Black Sea", 60));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Baltic", 60));
    gameBoard.appendCell(GameCell::makeTaxCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Down, "Reading", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Oriental", 100));
    gameBoard.appendCell(GameCell::makeChanceCell(NULL, CellPosition::Down));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Vermont", 100));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Connecticut", 120));
    gameBoard.appendCell(GameCell::makeJailCell(NULL));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "St. Charles", 140));
    gameBoard.appendCell(GameCell::makeCompanyCell(NULL, CellPosition::Left, "Electric Company", 150));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "States", 140));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "Virginia", 160));
    gameBoard.appendCell(GameCell::makeRailroadCell(NULL, CellPosition::Left, "Pennsylvania", 200));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "St. James", 180));
    gameBoard.appendCell(GameCell::makeChestCell(NULL, CellPosition::Left));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "Tennessee", 180));
    gameBoard.appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "New York", 200));

    for (int i=0; i<2; i++) {
        gameBoard.appendPlayer(Player::makePlayer("Player " + std::to_string(i+1), 1500, 20));
    }

    gameBoard.startGame();
    gameBoard.players[1]->balance = 0; // explanation: PLAYER 2 HAS $0 AFTER THIS LINE OF CODE
    
    CHECK(gameBoard.cells.size() == 40);
    CHECK(gameBoard.players.size() == 2);
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getGameState() == GameState::ManageAssetsOrRollDice); // explanation: GameState that allows player to roll dice
    CHECK(gameBoard.getActivePlayer()->cellIndex == 20); // explanation: index of Start Space is 20
    gameBoard.pushDice(4, 5); // explanation: put dice
    CHECK(gameBoard.getActivePlayerId() == 0);
    CHECK(gameBoard.getActivePlayer()->cellIndex == 29); // explanation: player 1 moved to Connecticut Avenue
    gameBoard.updateActivePlayerAssets(); // explanation: list his assets
    CHECK(gameBoard.getActivePlayerCellCounter() == 0);  // explanation: he must have 0 cell (property) at the start
    gameBoard.pushAction(GameAction::BuyProperty, 29); // explanation: player 1 buys Connecticut Avenue (space #29)
    gameBoard.updateActivePlayerAssets(); // explanation: list his assets
    CHECK(gameBoard.getActivePlayerCellCounter() == 1);  // explanation: he must have 1 cell (property) now
    CHECK(gameBoard.getActivePlayer()->balance == 1380); // explanation: player 1 has $1380 now (he paid $120 to buy Connecticut Avenue)
    gameBoard.nextPlayer(); // explanation: next turn, player 2
    CHECK(gameBoard.getActivePlayerId() == 1);
    CHECK(gameBoard.getActivePlayer()->balance == 0); // explanation: initial balance of player 2 in this test is $0
    gameBoard.pushDice(4, 5); // explanation: put dice
    CHECK(gameBoard.getActivePlayer()->balance == -12); // explanation: new balance of player 2, no money to pay fee
    gameBoard.updateActivePlayerAssets(); // explanation: check if player 2 has any property to sell (he has NONE)
    CHECK(gameBoard.getGameState() == GameState::Bankrupt); // explanation: now he is bankrupt
    gameBoard.removeActivePlayer(); // explanation: remove bankrupt player
    CHECK(gameBoard.checkGameOver() == true); // explanation: game is over now
    CHECK(gameBoard.getGameState() == GameState::GameOver);
    CHECK(gameBoard.players.size() == 1); // explanation: only 1 player left in the game
    CHECK(gameBoard.players[0]->name == "Player 1"); // explanation: player 1 is the only player left - he wins!!!
}
