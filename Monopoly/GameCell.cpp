#include "GameCell.hpp"

#define GAMECELL_POSSESSIONRECT_DISTANCE1 3
#define GAMECELL_POSSESSIONRECT_DISTANCE2 1

GameCell *GameCell::makeStartCell(sf::Texture *texture) {
    return makeFullSquareCell(texture, CellType::Start);
}

GameCell *GameCell::makeFreeParkingCell(sf::Texture *texture) {
    return makeFullSquareCell(texture, CellType::FreeParking);
}

GameCell *GameCell::makeGotoJailCell(sf::Texture *texture) {
    return makeFullSquareCell(texture, CellType::GotoJail);
}

GameCell *GameCell::makeJailCell(sf::Texture *texture) {
    return makeFullSquareCell(texture, CellType::Jail);
}

GameCell *GameCell::makeFullSquareCell(sf::Texture *texture, CellType type) {
    GameCell *cell = new GameCell();
    cell->type = type;
    if (NULL != texture) {
        cell->cellSprite.setTexture(*texture);
        cell->cellSpriteOn = true;
    }
    return cell;
}

GameCell *GameCell::makeChestCell(sf::Texture *texture, CellPosition cellPosition) {
    return makeFullRectangleSpriteCell(texture, cellPosition, CellType::Chest);
}

GameCell *GameCell::makeChanceCell(sf::Texture *texture, CellPosition cellPosition) {
    return makeFullRectangleSpriteCell(texture, cellPosition, CellType::Chance);
}

GameCell *GameCell::makeTaxCell(sf::Texture *texture, CellPosition cellPosition) {
    return makeFullRectangleSpriteCell(texture, cellPosition, CellType::Tax);
}

GameCell *GameCell::makeFullRectangleSpriteCell(sf::Texture *texture, CellPosition cellPosition, CellType type) {
    GameCell *cell = new GameCell();
    cell->type = type;
    cell->cellPosition = cellPosition;
    if (NULL != texture) {
        cell->cellSprite.setTexture(*texture);
        cell->cellSpriteOn = true;
        if (CellPosition::Left==cellPosition) {
            cell->cellSprite.rotate(90);
        }
        else if (CellPosition::Right==cellPosition) {
            cell->cellSprite.rotate(270);
        }
    }
    return cell;
}

GameCell *GameCell::makeRailroadCell(sf::Texture *texture, CellPosition cellPosition, std::string name, int price) {
    GameCell *cell = makeFullRectangleSpriteCell(texture, cellPosition, CellType::RailRoad);
    cell->name = name;
    cell->price = price;
    return cell;
}

GameCell *GameCell::makeCompanyCell(sf::Texture *texture, CellPosition cellPosition, std::string name, int price) {
    GameCell *cell = makeFullRectangleSpriteCell(texture, cellPosition, CellType::Company);
    cell->name = name;
    cell->price = price;
    return cell;
}

GameCell *GameCell::makeStreetCell(StreetGroup group, CellPosition cellPosition, std::string name, int price) {
    GameCell *cell = new GameCell();
    cell->type = CellType::Street;
    cell->cellPosition = cellPosition;
    cell->name = name;
    cell->price = price;
    cell->group = group;
    return cell;
}

void GameCell::drawEdge(GameWindow *gameWindow, const sf::Color &color) {
    sf::RectangleShape shape(sf::Vector2f(rectWidth, rectHeight));
    shape.setFillColor(GAMECELL_BACKGROUNDCOLOR);
    shape.setOutlineColor(color);
    shape.setOutlineThickness(GAMECELL_OUTLINESIZE);
    shape.setPosition(sf::Vector2f(rectX, rectY));
    gameWindow->draw(shape);
}

void GameCell::draw(GameWindow *gameWindow) {
    drawEdge(gameWindow, GAMECELL_EDGECOLOR);
    if (cellSpriteOn) {
        float scaleVal;
        if ((CellType::Start == type) || (CellType::FreeParking == type) || (CellType::GotoJail == type) || (CellType::Jail == type)) {
            scaleVal = (float)(gameWindow->getCellBaseSize()*1.5 - 2*GAMECELL_OUTLINESIZE) / (float)(cellSprite.getTexture()->getSize().x);
        } else {
            scaleVal = (float)(gameWindow->getCellBaseSize() - 2*GAMECELL_OUTLINESIZE) / (float)(cellSprite.getTexture()->getSize().x);
        }
        cellSprite.setScale(scaleVal, scaleVal); // square texture only
        int x = 0;
        int y = 0;
        if ((CellType::Chest == type) || (CellType::Chance == type) || (CellType::Tax == type) || (CellType::RailRoad == type) || (CellType::Company == type)) {
            if (CellPosition::Left==cellPosition) {
                x += gameWindow->getCellBaseSize()*3/2 - 2*GAMECELL_OUTLINESIZE;
            } else if (CellPosition::Right==cellPosition) {
                y += gameWindow->getCellBaseSize() - 2*GAMECELL_OUTLINESIZE;
            }
        } else {
            if (CellPosition::Down==cellPosition) {
                y += gameWindow->getCellBaseSize()/2;
            } else if (CellPosition::Right==cellPosition) {
                x += gameWindow->getCellBaseSize()/2;
            }
        }
        if ((CellType::Company == type) && (CellPosition::Up==cellPosition)) {
            y += gameWindow->getCellBaseSize() * 2 / 7;
        }
        cellSprite.setPosition(rectX+GAMECELL_OUTLINESIZE+x, rectY+GAMECELL_OUTLINESIZE+y);
        gameWindow->draw(cellSprite);
    }
    if ((CellType::Street == type) || (CellType::Company == type) || (CellType::RailRoad == type)) {
        if ((CellType::RailRoad == type)) {
            drawRailroadName(gameWindow, sf::Color::White);
        } else if ((CellType::Street == type)) {
            drawStreetGroup(gameWindow);
            drawStreetName(gameWindow, sf::Color::White);
        }
        drawPrice(gameWindow, sf::Color::White);
        drawPossessionStatus(gameWindow);
    }
}

void GameCell::drawPrice(GameWindow *gameWindow, const sf::Color &color) {
    if (NOTAVAILABLEVALUE != owner) return;
    int rotate;
    int dx, dy;
    if (CellPosition::Up == cellPosition) {
        dx = gameWindow->getCellBaseSize() / 2;
        dy = gameWindow->getCellBaseSize() * 1/6;
        rotate = 0;
    }
    else if (CellPosition::Down == cellPosition) {
        dx = gameWindow->getCellBaseSize() / 2;
        dy = gameWindow->getCellBaseSize() * 6/5;
        rotate = 0;
    }
    else if (CellPosition::Left == cellPosition) {
        dy = gameWindow->getCellBaseSize() * 1/2;
        dx = gameWindow->getCellBaseSize() * 1/2 - GAMECELL_OUTLINESIZE*2;
        rotate = 90;
    }
    else if (CellPosition::Right == cellPosition) {
        dy = gameWindow->getCellBaseSize() * 1/2;
        dx = gameWindow->getCellBaseSize() * 6/5;
        rotate = 270;
    }
    gameWindow->drawText(std::to_string(price), 3, color, rectX+dx, rectY+dy, rotate, true);
}

void GameCell::drawRailroadName(GameWindow *gameWindow, const sf::Color &color) {
    int rotate;
    int dx, dy;
    if (CellPosition::Left == cellPosition) {
        dy = gameWindow->getCellBaseSize() / 2;
        dx = gameWindow->getCellBaseSize() * 3/2;
        rotate = 90;
    } else if (CellPosition::Right == cellPosition) {
        dy = gameWindow->getCellBaseSize() * 1/2;
        dx = gameWindow->getCellBaseSize() / 5;
        rotate = 270;
    } else if (CellPosition::Down == cellPosition) {
        dx = gameWindow->getCellBaseSize() / 2;
        dy = gameWindow->getCellBaseSize() / 5;
        rotate = 0;
    } else {
        dx = gameWindow->getCellBaseSize() / 2;
        dy = gameWindow->getCellBaseSize() * 5 / 4;
        rotate = 0;
    }
    gameWindow->drawText(name, 0, color, rectX+dx, rectY+dy, rotate, true);
}

void GameCell::drawStreetGroup(GameWindow *gameWindow) {
    if (CellType::Street != type) return;
    int x, y, width, height;
    if (CellPosition::Up == cellPosition) {
        width = gameWindow->getCellBaseSize() - 2*GAMECELL_OUTLINESIZE;
        height = gameWindow->getCellBaseSize()/ 5;
        x = rectX + GAMECELL_OUTLINESIZE;
        y = rectY + gameWindow->getCellBaseSize()*3/2 - GAMECELL_OUTLINESIZE - height;
    } else if (CellPosition::Down == cellPosition) {
        width = gameWindow->getCellBaseSize() - 2;
        height = gameWindow->getCellBaseSize()/ 5;
        x = rectX + GAMECELL_OUTLINESIZE;
        y = rectY + GAMECELL_OUTLINESIZE;
    } else if (CellPosition::Right == cellPosition) {
        width = gameWindow->getCellBaseSize()/ 5;
        height = gameWindow->getCellBaseSize() - 2*GAMECELL_OUTLINESIZE;
        x = rectX + GAMECELL_OUTLINESIZE;
        y = rectY + GAMECELL_OUTLINESIZE;
    } else if (CellPosition::Left == cellPosition) {
        width = gameWindow->getCellBaseSize()/ 5;
        height = gameWindow->getCellBaseSize() - 2*GAMECELL_OUTLINESIZE;
        x = rectX + gameWindow->getCellBaseSize()*3/2 - GAMECELL_OUTLINESIZE - width;
        y = rectY + GAMECELL_OUTLINESIZE;
    } else return;
    sf::RectangleShape shape(sf::Vector2f(width, height));
    switch (group) {
    case StreetGroup::Red:
        shape.setFillColor(sf::Color::Red);
        break;
    case StreetGroup::Yellow:
        shape.setFillColor(sf::Color::Yellow);
        break;
    case StreetGroup::Green:
        shape.setFillColor(sf::Color::Green);
        break;
    case StreetGroup::Blue:
        shape.setFillColor(sf::Color::Blue);
        break;
    case StreetGroup::Brown:
        shape.setFillColor(GAMEDEFINITION_BROWN);
        break;
    case StreetGroup::SkyBlue:
        shape.setFillColor(GAMEDEFINITION_SKYBLUE);
        break;
    case StreetGroup::Purple:
        shape.setFillColor(GAMEDEFINITION_PURPLE);
        break;
    case StreetGroup::Orange:
        shape.setFillColor(GAMEDEFINITION_ORANGE);
        break;
    default:
        break;
    }
    shape.setPosition(sf::Vector2f(x, y));
    gameWindow->draw(shape);
}

void GameCell::drawStreetName(GameWindow *gameWindow, const sf::Color &color) {
    int rotate;
    int dx, dy;
    if (CellPosition::Left == cellPosition) {
        dx = gameWindow->getCellBaseSize();
        dy = gameWindow->getCellBaseSize() / 2;
        rotate = 90;
    } else if (CellPosition::Right == cellPosition) {
        dx = gameWindow->getCellBaseSize() * 2 / 3;
        dy = gameWindow->getCellBaseSize() / 2;
        rotate = 270;
    } else {
        dx = gameWindow->getCellBaseSize() / 2;
        dy = gameWindow->getCellBaseSize() * 2 / 3;
        rotate = 0;
    }
    gameWindow->drawText(name, 0, color, rectX+dx, rectY+dy, rotate, true);
    if ((CellPosition::Up == cellPosition) || (CellPosition::Down == cellPosition)) {
        dy += gameWindow->getCellBaseSize()/5;
    } else if (CellPosition::Left == cellPosition) {
        dx -= gameWindow->getCellBaseSize()/4;
    } else {
        dx += gameWindow->getCellBaseSize()/5;
    }
    gameWindow->drawText("avenue", 0, color, rectX+dx, rectY+dy, rotate, true);
}

void GameCell::drawPossessionStatus(GameWindow *gameWindow) {
    if ((NOTAVAILABLEVALUE >= owner) || (MAXPLAYERS <= owner)) return;
    if ((CellType::Street != type) && (CellType::Company != type) && (CellType::RailRoad != type)) return;
    // draw flag
    int x, y, width, height;
    if (CellPosition::Up == cellPosition) {
        width = gameWindow->getCellBaseSize() - 2*GAMECELL_OUTLINESIZE;
        height = gameWindow->getCellBaseSize()/ 5;
        x = rectX + GAMECELL_OUTLINESIZE;
        y = rectY + GAMECELL_OUTLINESIZE;
    } else if (CellPosition::Down == cellPosition) {
        width = gameWindow->getCellBaseSize() - 2;
        height = gameWindow->getCellBaseSize()/ 5;
        x = rectX + GAMECELL_OUTLINESIZE;
        y = rectY + gameWindow->getCellBaseSize()*3/2 - GAMECELL_OUTLINESIZE - height;
    } else if (CellPosition::Right == cellPosition) {
        width = gameWindow->getCellBaseSize()/ 5;
        height = gameWindow->getCellBaseSize() - 2*GAMECELL_OUTLINESIZE;
        x = rectX + gameWindow->getCellBaseSize()*3/2 - GAMECELL_OUTLINESIZE - width;
        y = rectY + GAMECELL_OUTLINESIZE;
    } else if (CellPosition::Left == cellPosition) {
        width = gameWindow->getCellBaseSize()/ 5;
        height = gameWindow->getCellBaseSize() - 2*GAMECELL_OUTLINESIZE;
        x = rectX + GAMECELL_OUTLINESIZE;
        y = rectY + GAMECELL_OUTLINESIZE;
    } else return;
    sf::RectangleShape shape(sf::Vector2f(width, height));
    shape.setFillColor(gameWindow->getPlayerFlagColor(owner));
    shape.setPosition(sf::Vector2f(x, y));
    gameWindow->draw(shape);
    // draw upgrade level (possession status)
    if ((upgradeLevel <= 0) || (upgradeLevel > 5)) return;
    if (CellType::Street != type) return;
    int dx = 0;
    int dy = 0;
    int squareSize;
    if (width<height) {
        squareSize = width-2*GAMECELL_POSSESSIONRECT_DISTANCE1;
        dy = squareSize + GAMECELL_POSSESSIONRECT_DISTANCE2;
        y += (height - upgradeLevel*dy - GAMECELL_POSSESSIONRECT_DISTANCE2)/2;
        x += GAMECELL_POSSESSIONRECT_DISTANCE1;
    } else {
        squareSize = height-2*GAMECELL_POSSESSIONRECT_DISTANCE1;
        dx = squareSize + GAMECELL_POSSESSIONRECT_DISTANCE2;
        x += (width - upgradeLevel*dx - GAMECELL_POSSESSIONRECT_DISTANCE2)/2;
        y += GAMECELL_POSSESSIONRECT_DISTANCE1;
    }
    sf::RectangleShape possessionRect(sf::Vector2f(squareSize, squareSize));
    possessionRect.setPosition(x, y);
    possessionRect.setFillColor(sf::Color::Black);
    for (int i=0; i<upgradeLevel; i++) {
        gameWindow->draw(possessionRect);
        possessionRect.move(dx, dy);
    }
}

void GameCell::drawCellInfo(GameWindow *gameWindow, int x, int y) {
    // indicator rect
    sf::RectangleShape shape(sf::Vector2f(rectWidth, rectHeight));
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineColor(sf::Color::Green);
    shape.setOutlineThickness(GAMECELL_OUTLINESIZE);
    shape.setPosition(sf::Vector2f(rectX, rectY));
    gameWindow->draw(shape);
    // info
    std::string dispStr = name;
    if (CellType::Start == type) dispStr = "Start";
    if (CellType::FreeParking == type) dispStr = "Free Parking";
    if (CellType::GotoJail == type) dispStr = "Go to Jail";
    if (CellType::Jail == type) dispStr = "Jail";
    if (CellType::Chance == type) dispStr = "Chance / Surprise";
    if (CellType::Chest == type) dispStr = "Community Chest";
    if (CellType::Tax == type) dispStr = "Tax";
    if (CellType::Company == type) dispStr += " Company";
    if (CellType::RailRoad == type) dispStr += " Railroad";
    if (CellType::Street == type) dispStr += " Avenue";
    gameWindow->drawText(dispStr, 4, sf::Color::White, x, y, 0, true);
    if ((CellType::Company != type) && (CellType::RailRoad != type) && (CellType::Street != type)) return;
    int dy = gameWindow->getCellBaseSize()/2;
    y += dy;
    if (owner <= NOTAVAILABLEVALUE) {
        gameWindow->drawText("Not owned by anyone", 4, sf::Color::White, x, y, 0, true);
    } else {
        gameWindow->drawText("Owned by " + gameWindow->getGameBoard()->getPlayerFromId(owner)->name, 4, gameWindow->getPlayerFlagColor(owner), x, y, 0, true);
        if (CellType::Street == type) {
            y += dy;
            dispStr = "Upgrade status: ";
            if (upgradeLevel==5) {
                dispStr += "Hotel built";
            } else {
                dispStr += std::to_string(upgradeLevel) + " house(s) built";
            }
            gameWindow->drawText(dispStr, 4, gameWindow->getPlayerFlagColor(owner), x, y, 0, true);
        }
    }
}
