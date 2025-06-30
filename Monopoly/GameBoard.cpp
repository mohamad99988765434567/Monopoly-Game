#include "GameBoard.hpp"

GameBoard::~GameBoard() {
    std::vector<GameCell*>::iterator iter;
    for (iter = cells.begin(); iter != cells.end(); iter++) {
        delete *iter;
    }
    std::vector<Player*>::iterator iter2;
    for (iter2 = players.begin(); iter2 != players.end(); iter2++) {
        delete *iter2;
    }
    players.clear();
    cells.clear();
    gameLogs.clear();
}

void GameBoard::appendLog(std::string str) {
    gameLogs.push_back(str);
}

void GameBoard::createLog(std::string str) {
    gameLogs.clear();
    appendLog(str);
}

void GameBoard::draw() {
    if (NULL == mGameWindow) return;
    std::vector<GameCell *>::iterator iter;
    for (iter = cells.begin(); iter != cells.end(); iter++) {
        (*iter)->draw(mGameWindow);
    }
    std::vector<Player *>::iterator iter2;
    for (iter2 = players.begin(); iter2 != players.end(); iter2++) {
        (*iter2)->drawInactive(mGameWindow, this);
    }
    for (iter2 = players.begin(); iter2 != players.end(); iter2++) {
        if ((*iter2)->playerId == mActivePlayerId) {
            (*iter2)->drawActive(mGameWindow, this);
            break;
        }
    }
}

void GameBoard::appendCell(GameCell *cell) {
    cells.push_back(cell);
    if (CellType::Jail == cell->type) {
        mJailIndex = cells.size()-1;
    }
    if (CellType::Start == cell->type) {
        mStartIndex = cells.size()-1;
    }
}

GameCell *GameBoard::getGameCellAt(int idx) {
    if ((idx < 0) || (idx >= cells.size())) return NULL;
    return cells[idx];
}

bool GameBoard::appendPlayer(Player *player) {
    if ((mGameState != GameState::NotEnoughPlayer) && (mGameState != GameState::ReadyToStart)) return false;
    if ((players.size()>=8) || (mNextAvaiableId >= 8)) return false;
    player->playerId = mNextAvaiableId;
    mNextAvaiableId++;
    players.push_back(player);
    mActivePlayerId = 0;
    if (players.size() >= 2) mGameState = GameState::ReadyToStart;
    return true;
}

void GameBoard::removeActivePlayer() {
    std::vector<Player*>::iterator iter;
    for (iter = players.begin(); iter != players.end(); iter++) {
        if ((*iter)->playerId == mActivePlayerId) {
            delete *iter;
            players.erase(iter);
            mActivePlayerId = NOTAVAILABLEVALUE;
            return;
        }
    }
}

Player *GameBoard::getPlayerFromId(int playerId) {
    std::vector<Player *>::iterator iter2;
    for (iter2 = players.begin(); iter2 != players.end(); iter2++) {
        if ((*iter2)->playerId == playerId) {
            return (*iter2);
        }
    }
    return NULL;
}

bool GameBoard::startGame() {
    if (GameState::ReadyToStart != mGameState ) return false;
    if ((NOTAVAILABLEVALUE == mJailIndex) || (NOTAVAILABLEVALUE == mStartIndex)) return false;
    if (getActivePlayer()->balance < 0) {
        mGameState = GameState::NegativeBalance;
        mNegativeBeforeRollingDice = true;
    } else {
        mGameState = GameState::ManageAssetsOrRollDice;
    }
    return true;
}

bool GameBoard::checkGameOver() {
    if (GameState::GameOver == mGameState) {
        return true;
    }
    if ((GameState::NotEnoughPlayer == mGameState) || (GameState::ReadyToStart == mGameState)) return false;
    if (players.size()==0) return false;
    if (players.size()==1) {
        mGameState = GameState::GameOver;
        mWinnerId = players[0]->playerId;
        return true;
    }
    int richest = 0;
    for (int i=1; i<players.size(); i++) {
        if (players[richest]->balance < players[i]->balance) richest = i;
    }
    if ((players[richest]->balance>=GAMERULE_WINNERBALANCE) || (players[richest]->balance < 0)) { // note: if all players have negative balance, the player with max int balance win
        mGameState = GameState::GameOver;
        mWinnerId = richest;
        return true;
    }
    mWinnerId = NOTAVAILABLEVALUE;
    return false;
}

bool GameBoard::nextPlayer() {
    if ((GameState::ManageAssetsOrNextPlayer != mGameState) && (GameState::Bankrupt != mGameState))return false;
    if (players.size()==0) {
        mActivePlayerId = NOTAVAILABLEVALUE;
        return false;
    }
    // Note: mActivePlayerId seeks to the old active player (he could be deleted already, but it's ok)
    // clear task
    mDoubleCount = 0;
    gameLogs.clear();
    mGameState = GameState::ManageAssetsOrRollDice;
    // search task
    Player *nextActivePlayer = NULL;
    std::vector<Player *>::iterator iter;
    for (iter = players.begin(); iter != players.end(); iter++) {
        if ((*iter)->playerId > mActivePlayerId) {
            nextActivePlayer = *iter;
            break;
        }
    }
    if (NULL == nextActivePlayer) nextActivePlayer = players[0];
    mActivePlayerId = nextActivePlayer->playerId;
    if (nextActivePlayer->isParking) {
        nextActivePlayer->isParking = false;
        mGameState = GameState::ManageAssetsOrNextPlayer; // ust to make the recursion available, this value will never really returned
        return nextPlayer(); // recursion to find other player
    }
    if (nextActivePlayer->balance < 0) {
        mGameState = GameState::NegativeBalance;
        mNegativeBeforeRollingDice = true;
    }
    return true;
}

void GameBoard::updateActivePlayerAssets() {
    mPlayerCells = 0;
    mPlayerHotels = 0;
    mPlayerHouses = 0;
    mPlayerTotalAssetValue = 0;
    Player *player = getActivePlayer();
    if (NULL == player) return;
    mPlayerTotalAssetValue = player->balance;
    std::vector<GameCell *>::iterator iter;
    for (iter = cells.begin(); iter != cells.end(); iter++) {
        GameCell *cell = *iter;
        if (cell->owner == mActivePlayerId) {
            mPlayerCells++;
            mPlayerTotalAssetValue += cell->price/2;
            if (CellType::Street == cell->type) {
                if (5 == cell->upgradeLevel) {
                    mPlayerHotels++;
                    mPlayerHouses+=4;
                    mPlayerTotalAssetValue += cell->price*2 + 50;
                } else {
                    mPlayerHouses+=cell->upgradeLevel;
                    mPlayerTotalAssetValue += cell->price*cell->upgradeLevel/4;
                }
            }
        }
    }
    if (mPlayerTotalAssetValue < 0) {
        mGameState = GameState::Bankrupt;
    }
}

void GameBoard::checkAndRewardIfPassedStartCell(int oldIndex, int newIndex) {
    int i = oldIndex;
    while (i!=newIndex) {
        i++;
        if (i>=cells.size()) i=0;
        if (CellType::Start == getGameCellAt(i)->type) {
            getActivePlayer()->balance += 200;
            appendLog("You got 200 ILS for passing Start");
            return;
        }
    }
}

// Rent fee for street:
//      0 house = 1/10 street price
//      1 house = 2/10 street price
//      2 house = 4/10 street price
//      3 house = 8/10 street price
//      4 house = 16/10 street price
//      1 hotel = 32/10 street price
// Rent fee for company:
//      last dice x 10
// Rent fee for railroad:
//      50 x number of railroad that owner owns
void GameBoard::processRentFeeAtNewCell() {
    Player *player = getActivePlayer();
    if (NULL == player) return;
    GameCell *cell = getGameCellAt(player->cellIndex);
    if (NULL == cell) return;
    if (cell->owner == NOTAVAILABLEVALUE) return;
    if (cell->owner == player->playerId) return;
    Player *owner = getPlayerFromId(cell->owner);
    if (NULL == owner) return;
    if ((CellType::Street != cell->type) && (CellType::Company != cell->type) && (CellType::RailRoad != cell->type)) return;
    int fee = 0;
    if (CellType::Street == cell->type) {
        fee = cell->price / 10 * pow(2, cell->upgradeLevel);
    } else if (CellType::Company == cell->type) {
        fee = lastDice * 10;
    } else {
        std::vector<GameCell *>::iterator iter;
        for (iter = cells.begin(); iter != cells.end(); iter++) {
            if ((CellType::RailRoad == (*iter)->type) && (owner->playerId == (*iter)->owner)) {
                fee += 50;
            }
        }
    }
    updateActivePlayerAssets();
    if (fee > mPlayerTotalAssetValue) { // process transfer all properties if active player will be bankrupt
        appendLog("You have to pay " + owner->name + " " + std::to_string(fee) + " ILS");
        owner->balance += player->balance;
        std::vector<GameCell *>::iterator iter;
        for (iter = cells.begin(); iter != cells.end(); iter++) {
            if ((*iter)->owner == mActivePlayerId) {
                (*iter)->owner = owner->playerId;
            }
        }
        player->balance = mPlayerTotalAssetValue - fee;
        appendLog("You have to pay " + owner->name + " " + std::to_string(fee) + " ILS");
        appendLog("you just transferred everything you have to " + owner->name);
        appendLog("you still owe " + owner->name + " " + std::to_string(player->balance) + " ILS and you are bankrupt");
        mGameState = GameState::Bankrupt;
    } else {
        addActivePlayerBalance(-fee, false); //player->balance -= fee;
        owner->balance += fee;
        appendLog("You just paid " + std::to_string(fee) + " ILS to " + owner->name);
    }
}

void GameBoard::justMovedActivePlayerToTheNewCell() {
    Player *player = getActivePlayer();
    if (NULL == player) return;
    GameCell *cell = getGameCellAt(player->cellIndex);
    if (NULL == cell) return;
    if (CellType::Chest == cell->type) {
        mGameState = GameState::WaitForChestValue;
    } else if (CellType::Chance == cell->type) {
        mGameState = GameState::WaitForChanceValue;
    } else if (CellType::Tax == cell->type) {
        appendLog("You pay a tax of 100 ILS");
        addActivePlayerBalance(-100, false); // player->balance -= 100;
    } else if (CellType::GotoJail == cell->type) {
        player->cellIndex = mJailIndex;
        player->isJailed = true;
        player->jailTurnCounter = 0;
        appendLog("You were jailed because of stopping at \"Go to Jail\" space");
        mDoubleCount = 0;
        mGameState = GameState::ManageAssetsOrNextPlayer;
    } else if (CellType::FreeParking == cell->type) {
        appendLog("Parking now. You will lose your next turn");
        player->isParking = true;
        mDoubleCount = 0;
        mGameState = GameState::ManageAssetsOrNextPlayer;
    } else {
        processRentFeeAtNewCell();
    }
}

bool GameBoard::pushDice_DoubleSubTask(int dice1, int dice2) {
    Player *player = getActivePlayer(); // sure not NULL
    if (dice1 == dice2) mDoubleCount++; else mDoubleCount = 0;
    if (player->isJailed) {
        if (player->jailTurnCounter >= 3) return false; // not allowed
        appendLog("Your dice are " + std::to_string(dice1) + " & " + std::to_string(dice2));
        if (dice1 == dice2) {
            appendLog("You get out of jail for rolling a Double");
            appendLog("You get an extra turn because you rolled a Double");
            player->isJailed = false;
            mDoubleCount = 0;
            return true;
        } else {
            player->jailTurnCounter++;
            if (player->jailTurnCounter==3) {
                player->isJailed = false;
                addActivePlayerBalance(-50, false); // player->balance -= 50;
                appendLog("Paid a fine of 50 ILS for being in jail for too long");
            } else {
                appendLog("Failed to roll a Double. Continue staying in jail");
            }
            mGameState = GameState::ManageAssetsOrNextPlayer;
            return true;
        }
    } else {
        appendLog("You got " + std::to_string(dice1+dice2) + " points from two dice (" + std::to_string(dice1) + " & " + std::to_string(dice2) + ")");
        if (dice1 == dice2) {
            if (mDoubleCount >= 3) {
                if (NOTAVAILABLEVALUE != mJailIndex) {
                    player->cellIndex = mJailIndex;
                    player->isJailed = true;
                    player->jailTurnCounter = 0;
                    appendLog("You were jailed for rolling Doubles three times in a row");
                    mDoubleCount = 0;
                    mGameState = GameState::ManageAssetsOrNextPlayer;
                    return true;
                }
            }
        }
        int oldCellIndex = player->cellIndex;
        player->cellIndex += dice1 + dice2;
        if (player->cellIndex >= cells.size()) player->cellIndex -= cells.size();
        checkAndRewardIfPassedStartCell(oldCellIndex, player->cellIndex);
        if (dice1 == dice2) {
            appendLog("You get an extra turn because you rolled a Double");
            return true;
        }
        mGameState = GameState::ManageAssetsOrNextPlayer;
    }
    return true;
}

bool GameBoard::pushDice(int dice1, int dice2) {
    if (GameState::ManageAssetsOrRollDice != mGameState ) return false;
    lastDice = dice1+dice2;
    Player *player = getActivePlayer();
    if (NULL == player) return false;
    int oldCellIndex = player->cellIndex;
    pushDice_DoubleSubTask(dice1, dice2);
    if (oldCellIndex == player->cellIndex) return true;
    justMovedActivePlayerToTheNewCell();
    return true;
}

bool GameBoard::teleportPlayer(std::string name, std::string foundMessage) {
    if (cells.size()==0) return false;
    Player *player = getActivePlayer(); // make sure not NULL
    for (int i=1; i<cells.size(); i++) {
        int idx = (player->cellIndex + i) % (cells.size());
        if (cells[idx]->name.compare(name) == 0) {
            appendLog(foundMessage);
            checkAndRewardIfPassedStartCell(player->cellIndex, idx);
            player->cellIndex = idx;
            justMovedActivePlayerToTheNewCell();
            return true;
        }
    }
    return false;
}

bool GameBoard::teleportPlayer(CellType type, std::string foundMessage) {
    if (cells.size()==0) return false;
    Player *player = getActivePlayer(); // make sure not NULL
    for (int i=1; i<cells.size(); i++) {
        int idx = (player->cellIndex + i) % (cells.size());
        if (cells[idx]->type == type) {
            appendLog(foundMessage);
            checkAndRewardIfPassedStartCell(player->cellIndex, idx);
            player->cellIndex = idx;
            justMovedActivePlayerToTheNewCell();
            return true;
        }
    }
    return false;
}

bool GameBoard::pushChestValue(int val) {
    if (val < 0) return false;
    if (GameState::WaitForChestValue != mGameState ) return false;
    Player *player = getActivePlayer();
    if (NULL == player) return false;
    switch (val % 8) {
    case 0:
        player->balance += 200;
        appendLog("Bank error in your favor. Collect 200 ILS");
        break;
    case 1:
        player->balance += 50;
        appendLog("From sale of stock you get 50 ILS");
        break;
    case 2:
        player->balance += 100;
        appendLog("Holiday fund matures. Receive 100 ILS");
        break;
    case 3:
        player->balance += 20;
        appendLog("Income tax refund. Collect 20 ILS");
        break;
    case 4:
        player->balance += 100;
        appendLog("Life insurance matures. Collect 100 ILS");
        break;
    case 5:
        player->balance += 25;
        appendLog("Receive 25 ILS consultancy fee");
        break;
    case 6:
        player->balance += 10;
        appendLog("Won a beauty contest. Collect 10 ILS");
        break;
    case 7:
        player->balance += 100;
        appendLog("You inherit 100 ILS");
        break;
    }
    if (player->balance >= 0) {
        if (mDoubleCount > 0) {
            mGameState = GameState::ManageAssetsOrRollDice;
        } else {
            mGameState = GameState::ManageAssetsOrNextPlayer;
        }
    }
    return true;
}

bool GameBoard::pushChanceValue(int val) {
    if (val < 0) return false;
    if (GameState::WaitForChanceValue != mGameState ) return false;
    Player *player = getActivePlayer();
    if (NULL == player) return false;
    switch (val % 16) {
    case 0:
        player->cellIndex = mStartIndex;
        player->balance += 200;
        appendLog("Advance to Go. Collect 200 ILS");
        break;
    case 1:
        player->balance += 50;
        appendLog("Bank pays you dividend of 50 ILS");
        break;
    case 2:
        player->cellIndex -= 3;
        if (player->cellIndex < 0) player->cellIndex += 40;
        appendLog("Go back 3 spaces");
        justMovedActivePlayerToTheNewCell();
        break;
    case 3:
        player->cellIndex = mJailIndex;
        player->isJailed = true;
        player->jailTurnCounter = 0;
        mDoubleCount = 0;
        mGameState = GameState::ManageAssetsOrNextPlayer;
        appendLog("Go directly to Jail");
        return true;
        break;
    case 4:
    {
        updateActivePlayerAssets();
        int cost = mPlayerHotels*100 + mPlayerHouses*25;
        addActivePlayerBalance(-cost, false); // player->balance -= cost;
        appendLog("Make general repairs. Each house 25 ILS, each hotel 100 ILS");
        appendLog("You pay " + std::to_string(cost) + " ILS");
        break;
    }
    case 5:
        addActivePlayerBalance(-15, false); // player->balance -= 15;
        appendLog("Pay poor tax of 15 ILS");
        break;
    case 6:
        if (!teleportPlayer("Reading", "Take a trip to Reading Railroad")) appendLog("Error: Reading railroad not found");
        break;
    case 7:
        if (!teleportPlayer("Broadwalk", "Take a walk on the Boardwalk")) appendLog("Error: Broadwalk not found");
        break;
    case 8:
    {
        std::vector<Player *>::iterator iter;
        for (iter = players.begin(); iter != players.end(); iter++) {
            if ((*iter)->playerId != mActivePlayerId) {
                (*iter)->balance += 50;
                addActivePlayerBalance(-50, false); // player->balance -= 50;
            }
        }
        appendLog("Elected Chairman of the Board, pay each player 50 ILS");
        break;
    }
    case 9:
        player->balance += 150;
        appendLog("Your building loan matures. Collect 150 ILS");
        break;
    case 10:
        player->pardonCardCounter++;
        appendLog("You get a pardon card to get out of jail free");
        break;
    case 11:
        if (!teleportPlayer("Illinois", "Advance to Illinois Avenue")) appendLog("Error: Illinois not found");
        break;
    case 12:
        if (!teleportPlayer("St. Charles", "Advance to St. Charles Avenue")) appendLog("Error: St. Charles not found");
        break;
    case 13:
    {
        updateActivePlayerAssets();
        int cost = mPlayerHotels*115 + mPlayerHouses*40;
        addActivePlayerBalance(-cost, false); // player->balance -= cost;
        appendLog("Street repairs. Each house 40 ILS, each hotel 115 ILS");
        appendLog("You pay " + std::to_string(cost) + " ILS");
        break;
    }
    case 14:
        if (!teleportPlayer(CellType::Company, "Advance to nearest Company")) appendLog("Error: no Company found");
        break;
    case 15:
        if (!teleportPlayer(CellType::RailRoad, "Advance to nearest Railroad")) appendLog("Error: no Railroad found");
        break;
    }
    if (player->balance >= 0) {
        if (mDoubleCount > 0) {
            mGameState = GameState::ManageAssetsOrRollDice;
        } else {
            mGameState = GameState::ManageAssetsOrNextPlayer;
        }
    }
    return true;
}

// upgrade cost
//      house 1: 1/2 street price
//      house 2: 1/2 street price
//      house 3: 1/2 street price
//      house 4: 1/2 street price
//      hotel: 2 x street price + 100
bool GameBoard::isActionAllowed(GameAction action, int cellIndex) {
    Player *player = getActivePlayer();
    if (NULL == player) return false;
    if (GameAction::UsePardonCard == action) {
        return (player->isJailed && (player->pardonCardCounter > 0) && (GameState::ManageAssetsOrRollDice == mGameState));
    } else if (GameAction::PayAFine == action) {
        return (player->isJailed && (player->balance >= 50) && (GameState::ManageAssetsOrRollDice == mGameState));
    } else {
        GameCell *cell = getGameCellAt(cellIndex);
        if (NULL == cell) return false;
        if (GameAction::BuyProperty == action) {
            bool diceRolled = false;
            if (GameState::ManageAssetsOrNextPlayer == mGameState) diceRolled = true;
            if ((GameState::ManageAssetsOrRollDice == mGameState) && (mDoubleCount > 0)) diceRolled = true;
            if (!diceRolled) return false; // you must roll the dice and move before you can buy property in this turn
            if (player->cellIndex != cellIndex) return false; // just buy the cell that active player is standing there
            if ((CellType::Street != cell->type) && (CellType::Company != cell->type) && (CellType::RailRoad != cell->type)) return false;
            return (cell->owner == NOTAVAILABLEVALUE) && (cell->price <= player->balance);
        } else if (GameAction::SellProperty == action) {
            if (cell->owner != mActivePlayerId) return false;;
            if (CellType::Street == cell->type) { // need to check: no street in the same group has a house/hotel
                std::vector<GameCell *>::iterator iter;
                for (iter = cells.begin(); iter != cells.end(); iter++) {
                    if ((CellType::Street == (*iter)->type) && (cell->group == (*iter)->group) && 
                    (mActivePlayerId == (*iter)->owner) && ((*iter)->upgradeLevel > 0)) { // you should downgrade this property first
                        return false;
                    }
                }
            }
            return true;
        } else if ((GameAction::UpgradeProperty == action) || (GameAction::DowngradeProperty == action)) {
            if (CellType::Street != cell->type) return false;
            int minLevel = 10000;
            int maxLevel = NOTAVAILABLEVALUE;
            std::vector<GameCell *>::iterator iter;
            for (iter = cells.begin(); iter != cells.end(); iter++) {
                if ((CellType::Street == (*iter)->type) && (cell->group == (*iter)->group)) {
                    if ((*iter)->owner != mActivePlayerId) return false;
                    if (minLevel > (*iter)->upgradeLevel) minLevel = (*iter)->upgradeLevel;
                    if (maxLevel < (*iter)->upgradeLevel) maxLevel = (*iter)->upgradeLevel;
                }
            }
            if (GameAction::UpgradeProperty == action) {
                int fee = cell->price/2;
                if (4 == cell->upgradeLevel) {
                    fee = fee*4 + 100;
                }
                return ((cell->upgradeLevel == minLevel) && (minLevel < 5) && (fee < player->balance));
            }
            return ((cell->upgradeLevel == maxLevel) && (maxLevel > 0)); // downgrade
        }
    }
    return false;
}

bool GameBoard::pushAction(GameAction action, int cellIndex) {
    if (!isActionAllowed(action, cellIndex)) return false;
    Player *player = getActivePlayer();
    if (NULL == player) return false;
    if (GameAction::UsePardonCard == action) {
        player->isJailed = false;
        player->pardonCardCounter--;
        player->jailTurnCounter = 0;
        mDoubleCount = 0;
        mGameState = GameState::ManageAssetsOrNextPlayer;
        appendLog("Get out of jail using Pardon Card");
    } else if (GameAction::PayAFine == action) {
        player->isJailed = false;
        player->balance -= 50;
        player->jailTurnCounter = 0;
        mDoubleCount = 0;
        mGameState = GameState::ManageAssetsOrNextPlayer;
        appendLog("Get out of jail by paying a fine of 50 ILS");
    } else {
        int fee;
        GameCell *cell = getGameCellAt(cellIndex);
        if (GameAction::BuyProperty == action) {
            cell->owner = mActivePlayerId;
            cell->upgradeLevel = 0;
            player->balance -= cell->price;
            appendLog("You spent " + std::to_string(cell->price) + " ILS to buy a new property");
        } else if (GameAction::SellProperty == action) {
            cell->owner = NOTAVAILABLEVALUE;
            cell->upgradeLevel = 0;
            appendLog("You sold a property for " + std::to_string(cell->price/2) + " ILS");
            addActivePlayerBalance(cell->price/2, true); // [true] not important in this case
        } else if (GameAction::UpgradeProperty == action) {
            if (cell->upgradeLevel < 5) {
                cell->upgradeLevel++;
                if (cell->upgradeLevel == 5) {
                    fee = cell->price*2 + 100;
                    appendLog("You spent " + std::to_string(fee) + " ILS to buy a new hotel");
                } else {
                    fee = cell->price/2;
                    appendLog("You spent " + std::to_string(fee) + " ILS to buy a new house");
                }
                player->balance -= fee;
            }
        } else if (GameAction::DowngradeProperty == action) {
            if (cell->upgradeLevel > 0) {
                cell->upgradeLevel--;
                if (cell->upgradeLevel == 4) {
                    fee = cell->price + 50;
                    appendLog("You sold a hotel for " + std::to_string(fee) + " ILS");
                } else {
                    fee = cell->price/4;
                    appendLog("You sold a house for " + std::to_string(fee) + " ILS");
                }
                addActivePlayerBalance(fee, true); // [true] not important in this case
            }
        }
    } 
    return true;
}

void GameBoard::addActivePlayerBalance(int amount, bool diceNotRolled) { // diceNotRolled useless if amount>=0
    if (GameState::Bankrupt == mGameState) return;
    Player *player = getActivePlayer();
    if ((NULL == player) || (0 == amount)) return;
    player->balance += amount;
    if (player->balance < 0) {
        if (GameState::NegativeBalance != mGameState) {
            mGameState = GameState::NegativeBalance;
            mNegativeBeforeRollingDice = diceNotRolled;
        }
    } else {
        if (GameState::NegativeBalance == mGameState) {
            if (mNegativeBeforeRollingDice) {
                mGameState = GameState::ManageAssetsOrRollDice;
            } else {
                if (mDoubleCount > 0) {
                    mGameState = GameState::ManageAssetsOrRollDice;
                } else {
                    mGameState = GameState::ManageAssetsOrNextPlayer;
                }
            }
        }
    }
}
