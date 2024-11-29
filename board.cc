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
// #include <unordered_set>
#include <iostream>

Board::Board() : rows{15}, cols{11}, picture{nullptr}, player{nullptr} {
}

Board::Board(int rows, int cols, Decorator* picture) : rows{rows}, cols{cols}, picture{picture} {}

Board::~Board() {
    delete picture;
}

char Board::getState(int x, int y) const {
    // Adding blind overlay
    if (player->getEffect() == Effect::BLIND) {
        if (x >= 2 && x <= 8 && y >= 5 && y <= 14) {
            return '?';
        }
    }
    return picture->charAt(x, y);
}

void Board::removeLayer(int row) { 
    // Remove tiles from row and block
    for (int c = 0; c < cols; ++c) {
        Decorator* curBlock = picture->blockAt(c, row);
        curBlock->removeTile(c, row);

        // If block is completely removed (all tiles gone), add to score
        if (curBlock->isEmpty()) {
            player->addScore((curBlock->getGeneratedLevel() + 1) * (curBlock->getGeneratedLevel() + 1));
        }
    }

    // std::unordered_set<Decorator*> movedBlocks;

    // Move above rows down by 1
    for (int r = row - 1; r >= 0; r--) {
        for (int c = 0; c < cols; c++) {
            Decorator* curBlock = picture->blockAt(c, r);
            if (curBlock) {
                curBlock->unconditionalMoveDown(r); 
            }
            
            // if (curBlock && !movedBlocks.count(curBlock)) {
            //     curBlock->unconditionalMoveDown(r); 
            //     movedBlocks.insert(curBlock);
            // }
        }
    }
}

int Board::checkBoard() {
    int linesCleared = 0;
    for (int r = 0; r < rows + 3; r++) {
        bool isFull = true;
        // Check each tile in row
        for (int c = 0; c < cols; c++) {
            if (!picture->blockAt(c,r)) {
                isFull = false;
            }
        }
        
        if (isFull) { 
            removeLayer(r);
            --r;
            linesCleared++;
        }
    }

    // Add points if an entire block is cleared
    if(linesCleared > 0){
        player->addScore((linesCleared + player->getLevel()->getLevelNum()) *
                     (linesCleared + player->getLevel()->getLevelNum()));
    }
    
    return linesCleared;
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

bool Board::setBlock(char block) {
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
    if (picture->hasOverlap()) {
        return false;
    }
    return true;
}

void Board::replaceBlock(char block) {
    Decorator* nextPic = picture->getComponent();
    picture->setComponentNull();
    delete picture;
    picture = nextPic;
    setBlock(block);
}

void Board::moveBlock(int rows, int cols) {
    if (rows == -1) {
        picture->moveLeft();
    } else if (rows == 1) {
        picture->moveRight();
    } else if (cols == 1) {
        picture->moveDown();
    }
    if (player->getEffect() == Effect::HEAVY) {
        picture->moveDown();
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

void Board::dropBlock() {
    picture->drop();
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
