#include "Player.hpp"

Player *Player::makePlayer(std::string name, int balance, int cellIndex) {
    Player *player = new Player();
    player->name = name;
    player->balance = balance;
    player->cellIndex = cellIndex;
    player->pardonCardCounter = 0;
    return player;
}

int Player::getRotateValue() {
    if ((0 <= cellIndex) && (10 > cellIndex)) return 270;
    if ((10 <= cellIndex) && (20 > cellIndex)) return 0;
    if ((20 <= cellIndex) && (30 > cellIndex)) return 90;
    return 180;
}

void Player::drawInactive(GameWindow *gameWindow, GameBoard *gameBoard) {
    if (gameBoard->getActivePlayerId() == playerId) return;
    if ((playerId>7) || (playerId<0)) return;
    if (cellIndex >= gameBoard->cells.size()) return;
    // prepare sprite
    sf::Sprite sprite;
    float scaleVal;
    int spriteWidth;
    int rotateVal = getRotateValue();
    scaleVal = (float)(gameWindow->getCellBaseSize()) * (2.0/5) / (float)(gameWindow->playerTexture[playerId].getSize().x);
    spriteWidth = (float)(gameWindow->playerTexture[playerId].getSize().x) * scaleVal;
    sprite.setTexture(gameWindow->playerTexture[playerId]);
    sprite.setScale(scaleVal, scaleVal);
    sprite.setRotation(rotateVal);
    if (rotateVal == 90) {
        sprite.setOrigin(0, gameWindow->playerTexture[playerId].getSize().x);
    } else if (rotateVal == 180) {
        sprite.setOrigin(gameWindow->playerTexture[playerId].getSize().x, gameWindow->playerTexture[playerId].getSize().x);
    } else if (rotateVal == 270) {
        sprite.setOrigin(gameWindow->playerTexture[playerId].getSize().x, 0);
    }
    // prepare bound
    int boundX, boundY;
    int counter = 0;
    int subIdx = 0;
    GameCell *cell = gameBoard->cells[cellIndex];
    std::vector<Player *>::iterator iter;
    for (iter = gameBoard->players.begin(); iter != gameBoard->players.end(); iter++) {
        if (((*iter)->cellIndex == cellIndex) && ((*iter)->playerId != gameBoard->getActivePlayerId()) && ((*iter)->isJailed == isJailed)) {
            if ((*iter)->playerId == playerId) {
                subIdx = counter;
            }
            counter++;
        }
    }
    if (CellType::Jail == cell->type) {
        if (!isJailed) {
            // special case, visit jail
            int visitEdge = (gameWindow->getCellBaseSize()/2-spriteWidth)/2;
            boundX = cell->rectX + gameWindow->getCellBaseSize() + visitEdge;
            boundY = cell->rectY + visitEdge;
            int visitHeight = gameWindow->getCellBaseSize()*3/2 - 2*visitEdge;
            int dy = spriteWidth;
            if (visitHeight < spriteWidth*counter) {
                dy = (visitHeight-spriteWidth)/(counter-1);
            }
            sprite.setPosition(boundX, boundY + subIdx*dy);
            gameWindow->draw(sprite);
            return;
        }
        boundX = cell->rectX + GAMECELL_OUTLINESIZE;
        boundY = cell->rectY + GAMECELL_OUTLINESIZE;
    } else {
        if ((CellType::Start == cell->type) || (CellType::GotoJail == cell->type) || (CellType::FreeParking == cell->type)) {
            boundX = cell->rectX + gameWindow->getCellBaseSize()/4;
            boundY = cell->rectY + gameWindow->getCellBaseSize()/4;
        } else {
            if (cellIndex < 10) {
                boundX = cell->rectX + GAMECELL_OUTLINESIZE;
                boundY = cell->rectY + gameWindow->getCellBaseSize()/4;
            } else if (cellIndex < 20) {
                boundX = cell->rectX + gameWindow->getCellBaseSize()/4;
                boundY = cell->rectY + GAMECELL_OUTLINESIZE;
            } else if (cellIndex < 30) {
                boundX = cell->rectX + GAMECELL_OUTLINESIZE;
                boundY = cell->rectY + gameWindow->getCellBaseSize()/4;
            } else {
                boundX = cell->rectX + gameWindow->getCellBaseSize()/4;
                boundY = cell->rectY + GAMECELL_OUTLINESIZE;
            }
        }
    }
    // calculate bound for the line of player
    if (counter<=4) {
        boundY += spriteWidth/2;
    } else {
        if (subIdx >= 4) {
            boundY += spriteWidth;
            subIdx -= 4;
            counter -= 4;
        } else { 
            counter = 4;
        }
    }
    int boundWidth = 2 * spriteWidth;
    int dx = 0;
    if (1 == counter) {
        boundX += spriteWidth/2;
    } else if (2 == counter) {
        dx = spriteWidth;
    } else if (3 == counter) {
        dx = spriteWidth/2;
    } else {
        dx = spriteWidth/3;
    }
    int y = boundY + gameWindow->getCellBaseSize() / 10;
    int x = boundX + dx * subIdx + gameWindow->getCellBaseSize() / 10;
    sprite.setPosition(x, y);
    gameWindow->draw(sprite);
}

void Player::drawActive(GameWindow *gameWindow, GameBoard *gameBoard) {
    if (gameBoard->getActivePlayerId() != playerId) return;
    if ((playerId>7) || (playerId<0)) return;
    if (cellIndex >= gameBoard->cells.size()) return;
    // prepare sprite
    sf::Sprite sprite;
    float scaleVal;
    int spriteWidth;
    int rotateVal = getRotateValue();
    scaleVal = (float)(gameWindow->getCellBaseSize()) * (2.0/3) / (float)(gameWindow->playerTexture[playerId].getSize().x);
    spriteWidth = (float)(gameWindow->playerTexture[playerId].getSize().x) * scaleVal;
    sprite.setTexture(gameWindow->playerTexture[playerId]);
    sprite.setScale(scaleVal, scaleVal);
    sprite.setRotation(rotateVal);
    if (rotateVal == 90) {
        sprite.setOrigin(0, gameWindow->playerTexture[playerId].getSize().x);
    } else if (rotateVal == 180) {
        sprite.setOrigin(gameWindow->playerTexture[playerId].getSize().x, gameWindow->playerTexture[playerId].getSize().x);
    } else if (rotateVal == 270) {
        sprite.setOrigin(gameWindow->playerTexture[playerId].getSize().x, 0);
    }
    // prepare position
    int x, y;
    GameCell *cell = gameBoard->cells[cellIndex];
    if ((CellType::Start == cell->type) || (CellType::GotoJail == cell->type) || (CellType::Jail == cell->type) || (CellType::FreeParking == cell->type)) {
        x = cell->rectX + gameWindow->getCellBaseSize()*3/4 - spriteWidth/2;
        y = cell->rectY + gameWindow->getCellBaseSize()*3/4 - spriteWidth/2;
    } else {
        if (cellIndex < 10) {
            x = cell->rectX + gameWindow->getCellBaseSize()/2 - spriteWidth/2;
            y = cell->rectY + gameWindow->getCellBaseSize()*3/4 - spriteWidth/2;
        } else if (cellIndex < 20) {
            x = cell->rectX + gameWindow->getCellBaseSize()*3/4 - spriteWidth/2;
            y = cell->rectY + gameWindow->getCellBaseSize()/2 - spriteWidth/2;
        } else if (cellIndex < 30) {
            x = cell->rectX + gameWindow->getCellBaseSize()/2 - spriteWidth/2;
            y = cell->rectY + gameWindow->getCellBaseSize()*3/4 - spriteWidth/2;
        } else {
            x = cell->rectX + gameWindow->getCellBaseSize()*3/4 - spriteWidth/2;
            y = cell->rectY + gameWindow->getCellBaseSize()/2 - spriteWidth/2;
        }
    }
    sprite.setPosition(x, y);
    gameWindow->draw(sprite);
}



