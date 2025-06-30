#include "GameWindow.hpp"

#define GAMEWINDOW_MARGIN 10

GameWindow::GameWindow() {
    srand(time(0));
    mGameBoard = new GameBoard();
    create();
}

GameWindow::~GameWindow() {
    if (mGameBoard) delete mGameBoard;
    destroy();
}

void GameWindow::create() {
    mRenderWindow.create(sf::VideoMode(), "Monopoly", sf::Style::Fullscreen);
    mGameBoard->setGameWindow(this);
}

void GameWindow::destroy() {
    mRenderWindow.close();
}

bool GameWindow::isOpen() {
    if (NULL == mGameBoard) return false;
    if (mIsStop) return false;
    return mRenderWindow.isOpen();
};

void GameWindow::drawText(std::string str, int fontSize, sf::Color color, int x, int y, int rotage, bool centerAlign) {
    sf::Text text;
    text.setFont(mFont);
    text.setString(str);
    if (fontSize < 0) fontSize = 0;
    if (fontSize > 4) fontSize = 4;
    text.setCharacterSize(mFontSize[fontSize]);
    text.setFillColor(color);
    text.setPosition(x,y);
    if (rotage) {
        text.setRotation(rotage);
    }
    if (centerAlign) {
        sf::FloatRect bound = text.getGlobalBounds();
        if (270 == rotage) bound.height = -bound.height;
        text.move(sf::Vector2f(-(int)bound.width/2, -(int)bound.height/2));
    }
    mRenderWindow.draw(text);
}

void GameWindow::calculateGameBoardLayout() {
    sf::Vector2u windowSize = mRenderWindow.getSize();
    if ((windowSize.x == mScreenWidth) || (windowSize.y == mScreenHeight)) return;
    if ((mScreenWidth != NOTAVAILABLEVALUE) || (mScreenHeight != NOTAVAILABLEVALUE)) {
        std::cout << std::endl << "Note: This game is a prototype and it does not support changing screen resolution while playing!" << std::endl << "Please try a new game!" << std::endl << std::endl;
        mIsStop = true;
        return;
    }
    mScreenWidth = windowSize.x;
    mScreenHeight = windowSize.y;
    mCellBaseSize = (mScreenHeight-2*GAMEWINDOW_MARGIN) / 12;
    mFontSize[0] = (int)(mScreenHeight*16/1080);
    mFontSize[1] = (int)(mScreenHeight*18/1080);
    mFontSize[2] = (int)(mScreenHeight*20/1080);
    mFontSize[3] = (int)(mScreenHeight*24/1080);
    mFontSize[4] = (int)(mScreenHeight*30/1080);
    GameCell *cell;
    for (int i=0; i<40; i++) {
        cell = mGameBoard->getGameCellAt(i);
        if (i%10==0) {
            cell->rectWidth = (int)((float)mCellBaseSize * 1.5);
            cell->rectHeight = cell->rectWidth;
        } else {
            if ((i/10)%2==0) {
                cell->rectWidth = mCellBaseSize;
                cell->rectHeight = (int)((float)mCellBaseSize * 1.5);
            } else {
                cell->rectWidth = (int)((float)mCellBaseSize * 1.5);
                cell->rectHeight = mCellBaseSize;
            }
        }
    }
    int leftX = (mScreenWidth-mScreenHeight)/2;
    cell = mGameBoard->getGameCellAt(0);
    cell->rectX = leftX + GAMEWINDOW_MARGIN;
    cell->rectY = GAMEWINDOW_MARGIN;
    cell = mGameBoard->getGameCellAt(10);
    cell->rectX = leftX + GAMEWINDOW_MARGIN + (int)((float)mCellBaseSize * 10.5);
    cell->rectY = GAMEWINDOW_MARGIN;
    cell = mGameBoard->getGameCellAt(20);
    cell->rectX = leftX + GAMEWINDOW_MARGIN + (int)((float)mCellBaseSize * 10.5);
    cell->rectY = GAMEWINDOW_MARGIN + (int)((float)mCellBaseSize * 10.5);
    cell = mGameBoard->getGameCellAt(30);
    cell->rectX = leftX + GAMEWINDOW_MARGIN;
    cell->rectY = GAMEWINDOW_MARGIN + (int)((float)mCellBaseSize * 10.5);
    for (int i=1; i<10; i++) {
        cell = mGameBoard->getGameCellAt(i);
        cell->rectX = leftX + GAMEWINDOW_MARGIN + (int)((float)mCellBaseSize * ((float)i+0.5));
        cell->rectY = GAMEWINDOW_MARGIN;
        cell = mGameBoard->getGameCellAt(i+10);
        cell->rectX = leftX + GAMEWINDOW_MARGIN + (int)((float)mCellBaseSize * 10.5);
        cell->rectY = GAMEWINDOW_MARGIN + (int)((float)mCellBaseSize * ((float)i+0.5));
        cell = mGameBoard->getGameCellAt(i+20);
        cell->rectX = leftX + GAMEWINDOW_MARGIN + (int)((float)mCellBaseSize * ((float)(10-i)+0.5));
        cell->rectY = GAMEWINDOW_MARGIN + (int)((float)mCellBaseSize * 10.5);
        cell = mGameBoard->getGameCellAt(i+30);
        cell->rectX = leftX + GAMEWINDOW_MARGIN;
        cell->rectY = GAMEWINDOW_MARGIN + (int)((float)mCellBaseSize * ((float)(10-i)+0.5));
    }
    int infoDistance = (mScreenWidth - mCellBaseSize*12) / 4;
    mPlayersInfoX = infoDistance;
    mCellAndActivePlayerInfo = mScreenWidth - infoDistance;
}

bool GameWindow::generateGameBoard() {
    if (
        (!mFont.loadFromFile("assets/Ubuntu-C.ttf")) ||
        (!startTexture.loadFromFile("assets/start2.png")) || 
        (!parkingTexture.loadFromFile("assets/parking2.png")) ||
        (!gotoJailTexture.loadFromFile("assets/gotojail.png")) ||
        (!jailTexture.loadFromFile("assets/jail2.png")) ||
        (!chestTexture.loadFromFile("assets/chest2.png")) ||
        (!chanceTexture.loadFromFile("assets/chance3.png")) ||
        (!taxTexture.loadFromFile("assets/tax2.png")) ||
        (!railroadTexture.loadFromFile("assets/railroad.png")) ||
        (!electricCompanyTexture.loadFromFile("assets/electric.png")) ||
        (!waterCompanyTexture.loadFromFile("assets/water2.png")) ||
        (!playerTexture[0].loadFromFile("assets/player1.png")) ||
        (!playerTexture[1].loadFromFile("assets/player2.png")) ||
        (!playerTexture[2].loadFromFile("assets/player3.png")) ||
        (!playerTexture[3].loadFromFile("assets/player4.png")) ||
        (!playerTexture[4].loadFromFile("assets/player5.png")) ||
        (!playerTexture[5].loadFromFile("assets/player6.png")) ||
        (!playerTexture[6].loadFromFile("assets/player7.png")) ||
        (!playerTexture[7].loadFromFile("assets/player8.png"))
    ) {
        std::cout << "Error: cannot load assets" << std::endl;
        return false;
    }
    mGameBoard->appendCell(GameCell::makeFreeParkingCell(&parkingTexture));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Kentucky", 220));
    mGameBoard->appendCell(GameCell::makeChanceCell(&chanceTexture, CellPosition::Up));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Indiana", 220));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::Red, CellPosition::Up, "Illinois", 240));
    mGameBoard->appendCell(GameCell::makeRailroadCell(&railroadTexture, CellPosition::Up, "B & O", 200));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Atantic", 260));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Ventnor", 260));
    mGameBoard->appendCell(GameCell::makeCompanyCell(&waterCompanyTexture, CellPosition::Up, "Water Company", 150));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::Yellow, CellPosition::Up, "Marvin", 280));
    mGameBoard->appendCell(GameCell::makeGotoJailCell(&gotoJailTexture));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pacific", 300));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Carolina", 300));
    mGameBoard->appendCell(GameCell::makeChestCell(&chestTexture, CellPosition::Right));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::Green, CellPosition::Right, "Pennsylvania", 320));
    mGameBoard->appendCell(GameCell::makeRailroadCell(&railroadTexture, CellPosition::Right, "Short Line", 200));
    mGameBoard->appendCell(GameCell::makeChanceCell(&chanceTexture, CellPosition::Right));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Broadwalk", 350));
    mGameBoard->appendCell(GameCell::makeTaxCell(&taxTexture, CellPosition::Right));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::Blue, CellPosition::Right, "Park Place", 400));
    mGameBoard->appendCell(GameCell::makeStartCell(&startTexture));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Black Sea", 60));
    mGameBoard->appendCell(GameCell::makeChestCell(&chestTexture, CellPosition::Down));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::Brown, CellPosition::Down, "Baltic", 60));
    mGameBoard->appendCell(GameCell::makeTaxCell(&taxTexture, CellPosition::Down));
    mGameBoard->appendCell(GameCell::makeRailroadCell(&railroadTexture, CellPosition::Down, "Reading", 200));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Oriental", 100));
    mGameBoard->appendCell(GameCell::makeChanceCell(&chanceTexture, CellPosition::Down));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Vermont", 100));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::SkyBlue, CellPosition::Down, "Connecticut", 120));
    mGameBoard->appendCell(GameCell::makeJailCell(&jailTexture));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "St. Charles", 140));
    mGameBoard->appendCell(GameCell::makeCompanyCell(&electricCompanyTexture, CellPosition::Left, "Electric Company", 150));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "States", 140));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::Purple, CellPosition::Left, "Virginia", 160));
    mGameBoard->appendCell(GameCell::makeRailroadCell(&railroadTexture, CellPosition::Left, "Pennsylvania", 200));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "St. James", 180));
    mGameBoard->appendCell(GameCell::makeChestCell(&chestTexture, CellPosition::Left));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "Tennessee", 180));
    mGameBoard->appendCell(GameCell::makeStreetCell(StreetGroup::Orange, CellPosition::Left, "New York", 200));

    // @@@DEBUG@@@ PART - COMMENT OUT

    // int val = 0;
    // mGameBoard->cells[1]->owner = val;
    // mGameBoard->cells[1]->upgradeLevel = 0;
    // mGameBoard->cells[8]->owner = val;
    // mGameBoard->cells[8]->upgradeLevel = 0;
    // // mGameBoard->cells[14]->owner = val;
    // // mGameBoard->cells[14]->upgradeLevel = 0;
    // // mGameBoard->cells[17]->owner = val;
    // // mGameBoard->cells[17]->upgradeLevel = 5;
    // // mGameBoard->cells[19]->owner = val;
    // // mGameBoard->cells[19]->upgradeLevel = 5;
    // mGameBoard->cells[26]->owner = val;
    // mGameBoard->cells[26]->upgradeLevel = 0;
    // mGameBoard->cells[31]->owner = val;
    // mGameBoard->cells[31]->upgradeLevel = 5;
    // mGameBoard->cells[32]->owner = val;
    // mGameBoard->cells[32]->upgradeLevel = 0;
    // mGameBoard->cells[33]->owner = val;
    // mGameBoard->cells[33]->upgradeLevel = 4;
    // mGameBoard->cells[34]->owner = val;
    // mGameBoard->cells[34]->upgradeLevel = 4;
    // mGameBoard->cells[35]->owner = val;
    // mGameBoard->cells[35]->upgradeLevel = 0;
    // mGameBoard->cells[36]->owner = val;
    // mGameBoard->cells[36]->upgradeLevel = 5;
    // mGameBoard->cells[38]->owner = val;
    // mGameBoard->cells[38]->upgradeLevel = 5;
    // mGameBoard->cells[39]->owner = val;
    // mGameBoard->cells[39]->upgradeLevel = 5;

    // val++;
    // mGameBoard->cells[5]->owner = val;
    // mGameBoard->cells[5]->upgradeLevel = 4;
    // mGameBoard->cells[8]->owner = val;
    // mGameBoard->cells[8]->upgradeLevel = 4;
    // mGameBoard->cells[21]->owner = val;
    // mGameBoard->cells[21]->upgradeLevel = 4;
    // mGameBoard->cells[23]->owner = val;
    // mGameBoard->cells[23]->upgradeLevel = 5;

    // mGameBoard->cells[21]->owner = 1;
    // mGameBoard->cells[21]->upgradeLevel = 5;
    // mGameBoard->cells[23]->owner = 1;
    // mGameBoard->cells[23]->upgradeLevel = 5;
    // mGameBoard->cells[26]->owner = 1;
    // mGameBoard->cells[26]->upgradeLevel = 3;
    // mGameBoard->cells[28]->owner = 1;
    // mGameBoard->cells[28]->upgradeLevel = 3;
    // mGameBoard->cells[29]->owner = 1;
    // mGameBoard->cells[29]->upgradeLevel = 3;

    // int val = 0;
    // mGameBoard->cells[1]->owner = val;
    // mGameBoard->cells[1]->upgradeLevel = 0;
    // mGameBoard->cells[14]->owner = val;
    // mGameBoard->cells[14]->upgradeLevel = 0;
    // mGameBoard->cells[26]->owner = val;
    // mGameBoard->cells[26]->upgradeLevel = 0;
    // mGameBoard->cells[33]->owner = val;
    // mGameBoard->cells[33]->upgradeLevel = 0;
    // mGameBoard->cells[34]->owner = val;
    // mGameBoard->cells[34]->upgradeLevel = 0;
    // mGameBoard->cells[36]->owner = val;
    // mGameBoard->cells[36]->upgradeLevel = 0;
    // mGameBoard->cells[5]->owner = val;
    // mGameBoard->cells[5]->upgradeLevel = 0;
    // mGameBoard->cells[35]->owner = val;
    // mGameBoard->cells[35]->upgradeLevel = 0;

    // int cellIndex = 33;
    // int playerId = 0;
    // mGameBoard->appendPlayer(Player::makePlayer(playerId++, "Player 1", 1500, cellIndex));
    // mGameBoard->appendPlayer(Player::makePlayer(playerId++, "Player 2", 1500, cellIndex));
    // mGameBoard->appendPlayer(Player::makePlayer(playerId++, "Player 3", 1500, cellIndex));
    // mGameBoard->appendPlayer(Player::makePlayer(playerId++, "Player 4", 1500, cellIndex));
    // mGameBoard->appendPlayer(Player::makePlayer(playerId++, "Player 5", 1500, cellIndex));
    // mGameBoard->appendPlayer(Player::makePlayer(playerId++, "Player 6", 1500, cellIndex));
    // mGameBoard->appendPlayer(Player::makePlayer(playerId++, "Player 7", 1500, cellIndex));
    // mGameBoard->appendPlayer(Player::makePlayer(playerId++, "Player 8", 1500, cellIndex));
    // mGameBoard->activePlayer = 0;
    // mCurrentCell = cellIndex;

    return true;
}

sf::Color GameWindow::getPlayerFlagColor(int playerIdx) {
    if (playerIdx < 0) return mPlayerColor[0];
    if (playerIdx > 8) return mPlayerColor[7];
    return mPlayerColor[playerIdx];
}

void GameWindow::showCurrentInfo() {
    int dy = mCellBaseSize/2;
    int y0 = (mScreenHeight - dy * mGameBoard->players.size() + 1) / 2;
    int y = y0;
    std::vector<Player *>::iterator iter2;
    for (iter2 = mGameBoard->players.begin(); iter2 != mGameBoard->players.end(); iter2++) {
        std::string dispStr = (*iter2)->name + ": " + Helper::getMoneyString((*iter2)->balance);
        drawText(dispStr, 4, getPlayerFlagColor((*iter2)->playerId), mPlayersInfoX, y, 0, true);
        y += dy;
    }
    if (mCurrentCell!=NOTAVAILABLEVALUE) {
        y = mScreenHeight/2 - dy*7;
        mGameBoard->cells[mCurrentCell]->drawCellInfo(this, mCellAndActivePlayerInfo, y);
    }
    showActivePlayerAssets();
    if (mGameBoard->getWinnerId() != NOTAVAILABLEVALUE) {
        drawText("Game Over", 4, sf::Color::Yellow, mScreenWidth/2, y0+dy*4, 0, true);
        drawText("The winner is " + mGameBoard->getPlayerFromId(mGameBoard->getWinnerId())->name, 4, sf::Color::White, mScreenWidth/2, y0+dy*5, 0, true);
    }
}

void GameWindow::showActivePlayerAssets() {
    Player *player = mGameBoard->getActivePlayer();
    if (NULL == player) return;
    mGameBoard->updateActivePlayerAssets();
    int dy = mCellBaseSize/2;
    int y = mScreenHeight/2 + dy * 2;
    drawText(player->name + " Asssets", 4, getPlayerFlagColor(player->playerId), mCellAndActivePlayerInfo, y, 0, true);
    y += dy;
    drawText("Balance = " + std::to_string(player->balance) + " ILS", 4, sf::Color::White, mCellAndActivePlayerInfo, y, 0, true);
    y += dy;
    drawText(std::to_string(mGameBoard->getActivePlayerCellCounter()) + " Property(ies)", 4, sf::Color::White, mCellAndActivePlayerInfo, y, 0, true);
    y += dy;
    drawText(std::to_string(mGameBoard->getActivePlayerHouseCounter()) + " House(s)", 4, sf::Color::White, mCellAndActivePlayerInfo, y, 0, true);
    y += dy;
    drawText(std::to_string(mGameBoard->getActivePlayerHotelCounter()) + " Hotel(s)", 4, sf::Color::White, mCellAndActivePlayerInfo, y, 0, true);
    y += dy;
    drawText(std::to_string(player->pardonCardCounter) + " Pardon Card(s)", 4, sf::Color::White, mCellAndActivePlayerInfo, y, 0, true);
    y += dy;
    drawText("Total Asset Value = " + std::to_string(mGameBoard->getActivePlayerTotalAssetValue()) + " ILS", 4, sf::Color::White, mCellAndActivePlayerInfo, y, 0, true);
}

void GameWindow::showGameLogs() {
    if (mGameBoard->gameLogs.size() == 0) return;
    int x = mScreenWidth/2;
    int y = mCellBaseSize*2;
    int dy = mCellBaseSize*2/5;
    int idx = mGameBoard->gameLogs.size()-13;
    if (idx < 0) idx = 0;
    for (; idx<mGameBoard->gameLogs.size(); idx++) {
        drawText(mGameBoard->gameLogs[idx], 3, sf::Color::Yellow, x, y, 0, true);
        y += dy;
    }
}

void GameWindow::showStateNotEnoughPlayer() {
    int dy = mCellBaseSize/2;
    int x = mScreenWidth/2;
    int y = mScreenHeight/2 + dy*3;
    drawText("Press keys 2 to 8 to select the number of players", 4, sf::Color::White, x, y, 0, true);
}

void GameWindow::processStateNotEnoughPlayer(sf::Keyboard::Key code) {
    int numPlayer = NOTAVAILABLEVALUE;
    if ((code == sf::Keyboard::Num2) || (code == sf::Keyboard::Numpad2)) numPlayer = 2;
    if ((code == sf::Keyboard::Num3) || (code == sf::Keyboard::Numpad3)) numPlayer = 3;
    if ((code == sf::Keyboard::Num4) || (code == sf::Keyboard::Numpad4)) numPlayer = 4;
    if ((code == sf::Keyboard::Num5) || (code == sf::Keyboard::Numpad5)) numPlayer = 5;
    if ((code == sf::Keyboard::Num6) || (code == sf::Keyboard::Numpad6)) numPlayer = 6;
    if ((code == sf::Keyboard::Num7) || (code == sf::Keyboard::Numpad7)) numPlayer = 7;
    if ((code == sf::Keyboard::Num8) || (code == sf::Keyboard::Numpad8)) numPlayer = 8;
    if (numPlayer < 2) return;
    for (int i=0; i<numPlayer; i++) {
        mGameBoard->appendPlayer(Player::makePlayer("Player " + std::to_string(i+1), 1500, 20));
    }
    mGameBoard->startGame();
}

bool GameWindow::processArrowKeys(sf::Keyboard::Key code) {
    if (sf::Keyboard::Left == code) {
        if ((0 < mCurrentCell) && (10 >= mCurrentCell)) {
            mCurrentCell--;
            return true;
        }
        if ((30 > mCurrentCell) && (20 <= mCurrentCell)) {
            mCurrentCell++;
            return true;
        }
        if ((20 > mCurrentCell) && (10 < mCurrentCell)) {
            mCurrentCell = 40 - (mCurrentCell - 10);
            return true;
        }
        return true;
    }
    if (sf::Keyboard::Right == code) {
        if ((0 <= mCurrentCell) && (10 > mCurrentCell)) {
            mCurrentCell++;
            return true;
        }
        if ((30 >= mCurrentCell) && (20 < mCurrentCell)) {
            mCurrentCell--;
            return true;
        }
        if (30 < mCurrentCell) {
            mCurrentCell = 10 + (40 - mCurrentCell);
            return true;
        }
        return true;
    }
    if (sf::Keyboard::Up == code) {
        if ((10 < mCurrentCell) && (20 >= mCurrentCell)) {
            mCurrentCell--;
            return true;
        }
        if (30 <= mCurrentCell) {
            mCurrentCell++;
            if (mCurrentCell == 40) mCurrentCell = 0;
            return true;
        }
        if ((30 > mCurrentCell) && (20 < mCurrentCell)) {
            mCurrentCell = 10 - (mCurrentCell - 20);
            return true;
        }
        return true;
    }
    if (sf::Keyboard::Down == code) {
        if ((10 <= mCurrentCell) && (20 > mCurrentCell)) {
            mCurrentCell++;
            return true;
        }
        if ((0 == mCurrentCell) || (30 < mCurrentCell)) {
            if (0 == mCurrentCell) mCurrentCell=40;
            mCurrentCell--;
            return true;
        }
        if ((10 > mCurrentCell) && (0 < mCurrentCell)) {
            mCurrentCell = 20 + (10 - mCurrentCell);
            return true;
        }
        return true;
    }
    return false;    
}

void GameWindow::displayAvailableActions(int x, int y, int dy) {
    GameCell *cell = mGameBoard->getGameCellAt(mCurrentCell);
    if (NULL != cell) {
        if (mGameBoard->isActionAllowed(GameAction::BuyProperty, mCurrentCell)) {
            y += dy;
            drawText("Press B to buy this property: -" + std::to_string(cell->price) + " ILS", 4, sf::Color::White, x, y, 0, true);
        }
        if (mGameBoard->isActionAllowed(GameAction::SellProperty, mCurrentCell)) {
            y += dy;
            drawText("Press S to sell this property: +" + std::to_string(cell->price/2) + " ILS", 4, sf::Color::White, x, y, 0, true);
        }
        if (mGameBoard->isActionAllowed(GameAction::UpgradeProperty, mCurrentCell)) {
            y += dy;
            if (mGameBoard->getGameCellAt(mCurrentCell)->upgradeLevel == 4) {
                int fee = cell->price*2 + 100;
                drawText("Press U to update this property (buy a hotel): -" + std::to_string(fee) + " ILS", 4, sf::Color::White, x, y, 0, true);
            } else {
                int fee = cell->price/2;
                drawText("Press U to update this property (buy a house): -" + std::to_string(fee) + " ILS", 4, sf::Color::White, x, y, 0, true);
            }
        }
        if (mGameBoard->isActionAllowed(GameAction::DowngradeProperty, mCurrentCell)) {
            y += dy;
            if (mGameBoard->getGameCellAt(mCurrentCell)->upgradeLevel == 5) {
                int fee = cell->price + 50;
                drawText("Press D to downgrade this property (sell the hotel): +" + std::to_string(fee) + " ILS", 4, sf::Color::White, x, y, 0, true);
            } else {
                int fee = cell->price/4;
                drawText("Press D to downgrade this property (sell a house): +" + std::to_string(fee) + " ILS", 4, sf::Color::White, x, y, 0, true);
            }
        }
    }
}

void GameWindow::showStateManageAssetsOrRollDice() {
    int dy = mCellBaseSize/2;
    int x = mScreenWidth/2;
    int y = mScreenHeight/2 + dy*3;
    drawText("Press space or enter to roll the dice", 4, sf::Color::White, x, y, 0, true);
    y += dy;
    drawText("Press arrow keys to view board information", 4, sf::Color::White, x, y, 0, true);
    if (mGameBoard->isActionAllowed(GameAction::UsePardonCard)) {
        y += dy;
        drawText("Press P to use Pardon Card", 4, sf::Color::White, x, y, 0, true);
    }
    if (mGameBoard->isActionAllowed(GameAction::PayAFine)) {
        y += dy;
        drawText("Press F to pay a fine of 50 ILS", 4, sf::Color::White, x, y, 0, true);
    }
    displayAvailableActions(x, y, dy);
    if (NOTAVAILABLEVALUE == mCurrentCell) mCurrentCell = mGameBoard->getActivePlayer()->cellIndex;
}

bool GameWindow::processActionKeys(sf::Keyboard::Key code) {
    if (sf::Keyboard::P == code) {
        mGameBoard->pushAction(GameAction::UsePardonCard);
        return true;
    }
    if (sf::Keyboard::F == code) {
        mGameBoard->pushAction(GameAction::PayAFine);
        return true;
    }
    if (sf::Keyboard::B == code) {
        mGameBoard->pushAction(GameAction::BuyProperty, mCurrentCell);
        return true;
    }
    if (sf::Keyboard::S == code) {
        mGameBoard->pushAction(GameAction::SellProperty, mCurrentCell);
        return true;
    }
    if (sf::Keyboard::U == code) {
        mGameBoard->pushAction(GameAction::UpgradeProperty, mCurrentCell);
        return true;
    }
    if (sf::Keyboard::D == code) {
        mGameBoard->pushAction(GameAction::DowngradeProperty, mCurrentCell);
        return true;
    }
    return false;
}

void GameWindow::processStateManageAssetsOrRollDice(sf::Keyboard::Key code) {
    if (processArrowKeys(code)) return;
    if ((sf::Keyboard::Space == code) || (sf::Keyboard::Enter == code)) {
        int dice1 = rand() % 6 + 1;
        int dice2 = rand() % 6 + 1;
        //dice1 = 5; dice2 = 6; // @@@debug@@@
        mGameBoard->pushDice(dice1, dice2);
        mCurrentCell = NOTAVAILABLEVALUE;
        return;
    }
    processActionKeys(code);
}

void GameWindow::showStateManageAssetsOrNextPlayer() {
    int dy = mCellBaseSize/2;
    int x = mScreenWidth/2;
    int y = mScreenHeight/2 + dy*3;
    drawText("Press space or enter to move to next player", 4, sf::Color::White, x, y, 0, true);
    y += dy;
    drawText("Press arrow keys to view board information", 4, sf::Color::White, x, y, 0, true);
    displayAvailableActions(x, y, dy);
    if (NOTAVAILABLEVALUE == mCurrentCell) mCurrentCell = mGameBoard->getActivePlayer()->cellIndex;
}

void GameWindow::processStateManageAssetsOrNextPlayer(sf::Keyboard::Key code) {
    if (processArrowKeys(code)) return;
    if ((sf::Keyboard::Space == code) || (sf::Keyboard::Enter == code)) {
        mGameBoard->nextPlayer();
        mCurrentCell = NOTAVAILABLEVALUE;
        return;
    }
    processActionKeys(code);
}

void GameWindow::showStateNegativeBalance() {
    int dy = mCellBaseSize/2;
    int x = mScreenWidth/2;
    int y = mScreenHeight/2 + dy*3;
    mGameBoard->updateActivePlayerAssets();
    drawText("Negative balance! You have to sell some properties", 4, sf::Color::White, x, y, 0, true);
    y += dy;
    drawText("Press arrow keys to view board information", 4, sf::Color::White, x, y, 0, true);
    displayAvailableActions(x, y, dy);
    if (NOTAVAILABLEVALUE == mCurrentCell) mCurrentCell = mGameBoard->getActivePlayer()->cellIndex;
}

void GameWindow::processStateNegativeBalance(sf::Keyboard::Key code) {
    if (processArrowKeys(code)) return;
    processActionKeys(code);
}

void GameWindow::showStateBankrupt() {
    int dy = mCellBaseSize/2;
    int x = mScreenWidth/2;
    int y = mScreenHeight/2 + dy*3;
    mGameBoard->updateActivePlayerAssets();
    drawText("You are bankrupt. Press space or enter to confirm", 4, sf::Color::White, x, y, 0, true);
    if (NOTAVAILABLEVALUE == mCurrentCell) mCurrentCell = mGameBoard->getActivePlayer()->cellIndex;
}

void GameWindow::processStateBankrupt(sf::Keyboard::Key code) {
    if ((sf::Keyboard::Space == code) || (sf::Keyboard::Enter == code)) {
        mGameBoard->removeActivePlayer();
        mGameBoard->nextPlayer();
        mCurrentCell = NOTAVAILABLEVALUE;
    }
}

void GameWindow::showStateWaitForChestValue() {
    int dy = mCellBaseSize/2;
    int x = mScreenWidth/2;
    int y = mScreenHeight/2 + dy*3;
    drawText("Opening community chest, please wait a moment", 4, sf::Color::White, x, y, 0, true);
    if (!mGameClockRestarted) {
        mGameClock.restart();
        mGameClockRestarted = true;
    } else {
        processStateWaitForChestValue();
    }
}

void GameWindow::processStateWaitForChestValue() {
    sf::Time eclapsed = mGameClock.getElapsedTime();
    if (eclapsed.asMilliseconds() >= 1500) {
        mGameClockRestarted = false;
        mGameBoard->pushChestValue(rand());
    }
}

void GameWindow::showStateWaitForChanceValue() {
    int dy = mCellBaseSize/2;
    int x = mScreenWidth/2;
    int y = mScreenHeight/2 + dy*3;
    drawText("Waiting for a random chance for you", 4, sf::Color::White, x, y, 0, true);
    if (!mGameClockRestarted) {
        mGameClock.restart();
        mGameClockRestarted = true;
    } else {
        processStateWaitForChanceValue();
    }
}

void GameWindow::processStateWaitForChanceValue() {
    sf::Time eclapsed = mGameClock.getElapsedTime();
    if (eclapsed.asMilliseconds() >= 1500) {
        mGameClockRestarted = false;
        mGameBoard->pushChanceValue(rand());
    }
}

void GameWindow::draw() {
    calculateGameBoardLayout();
    if (!mIsStop) mGameBoard->draw();
    if (mGameBoard->getGameState() == GameState::GameOver) {
    } else if (mGameBoard->getGameState() == GameState::NotEnoughPlayer) {
        showStateNotEnoughPlayer();
        return; // not show other info in this case
    } else if (mGameBoard->getGameState() == GameState::ManageAssetsOrRollDice) {
        showStateManageAssetsOrRollDice();
    } else if (mGameBoard->getGameState() == GameState::ManageAssetsOrNextPlayer) {
        showStateManageAssetsOrNextPlayer();
    } else if (mGameBoard->getGameState() == GameState::NegativeBalance) {
        showStateNegativeBalance();
    } else if (mGameBoard->getGameState() == GameState::Bankrupt) {
        showStateBankrupt();
    } else if (mGameBoard->getGameState() == GameState::WaitForChestValue) {
        showStateWaitForChestValue();
    } else if (mGameBoard->getGameState() == GameState::WaitForChanceValue) {
        showStateWaitForChanceValue();
    }
    showCurrentInfo();
    showGameLogs();
}

void GameWindow::update() {
    mGameBoard->checkGameOver();
    sf::Event event;
    while (mRenderWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            mIsStop = true;
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                mIsStop = true;
            } else {
                switch (mGameBoard->getGameState()) {
                case GameState::NotEnoughPlayer:
                    processStateNotEnoughPlayer(event.key.code);
                    break;
                case GameState::ManageAssetsOrRollDice:
                    processStateManageAssetsOrRollDice(event.key.code);
                    break;
                case GameState::ManageAssetsOrNextPlayer:
                    processStateManageAssetsOrNextPlayer(event.key.code);
                    break;
                case GameState::NegativeBalance:
                    processStateNegativeBalance(event.key.code);
                    break;
                case GameState::Bankrupt:
                    processStateBankrupt(event.key.code);
                    break;
                default:
                    break;
                }
            }
        }
    }
}

