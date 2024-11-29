#include "board.h"
#include "decorator.h"
#include "player.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include "iblock.h"
#include "lblock.h"
#include "jblock.h"
#include "player.h"
#include "blank.h"
#include <iostream>

Board::Board() : rows{15}, cols{11}, picture{nullptr}, player{nullptr} {
    // std::cout << "Default constructing board" << std::endl;
}

Board::Board(int rows, int cols, Decorator* picture) : rows{rows}, cols{cols}, picture{picture} {}

Board::~Board() {
    delete picture;
}

char Board::getState(int x, int y) const {
    if (!picture) {
        return ' ';
    }
    return picture->charAt(x, y);
}

Decorator* Board::getBlock(int x, int y) {
    if (!picture) {
        return nullptr;
    }
    return picture->blockAt(x, y);
}

void Board::removeLayer() {
    // TODO
}

void Board::checkBoard() {
    // TODO
}

int Board::getRows() const {
    return rows;
}

int Board::getCols() const {
    return cols;
}

void Board::setBlind(int rowStart, int rowEnd, int colStart, int colEnd) {
    // TODO
}

void Board::setBlock(char block) {
    if (block == 'O') {
        picture = new OBlock(picture, player->getLevel()->getLevelNum());
    } else if (block == 'T') {
        picture = new TBlock(picture, player->getLevel()->getLevelNum());
    } else if (block == 'I') {
        picture = new IBlock(picture, player->getLevel()->getLevelNum());
    } else if (block == 'J') {
        picture = new JBlock(picture, player->getLevel()->getLevelNum());
    } else if (block == 'L') {
        picture = new LBlock(picture, player->getLevel()->getLevelNum());
    } else if (block == 'S') {
        picture = new SBlock(picture, player->getLevel()->getLevelNum());
    } else if (block == 'Z') {
        picture = new ZBlock(picture, player->getLevel()->getLevelNum());
    }
}

void Board::moveBlock(int rows, int cols) {
    if (rows == -1) {
        picture->moveLeft();
    } else if (rows == 1) {
        picture->moveRight();
    } else if (cols == 1) {
        picture->moveDown();
    }
}

void Board::rotateBlock(bool clockwise) {
    if (clockwise) {
        picture->rotateClockwise();
    } else {
        picture->rotateCounterClockwise();
    }
}

bool Board::dropBlock() {
    return picture->drop();
}

void Board::setNextBlock(char block) {
    nextBlock = block;
}

int Board::getScore() const { return player->getScore(); }
// int Board::getScore() const { return 0; }

int Board::getLevel() const { return player->getLevel()->getLevelNum(); }
// int Board::getLevel() const {  return 1; }

char Board::getNextBlock() const { return nextBlock; }
// char Board::getNextBlock() const { return 'I'; }

std::string Board::getPlayerName() const { return player->getName(); }

void Board::setPlayer(Player* p) {
    player = p;
}
