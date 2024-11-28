#include "board.h"
#include "decorator.h"
#include "player.h"

Board::Board() : rows(15), cols(11) {}

// Board::Board(int rows, int cols, Decorator* picture) : rows{rows}, cols{cols}, picture{picture} {}

char Board::getState(int x, int y) const {
    char board[15][11] = {
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'T', 'T', 'T', '.', '.', '.', '.', '.', '.', '.', '.'}, // Simulate a T-block
        {'.', 'T', '.', '.', '.', '.', '.', '.', '.', '.', '.'}, // Bottom row of T-block
        {'I', 'I', 'I', 'I', '.', '.', '.', '.', '.', '.', '.'}  // Simulate an I-block
    };

    return board[x][y];
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
    // TODO
}

void Board::moveBlock(int rows, int cols) {
    if (rows == -1) {
        picture->moveLeft();
    } else if (rows == 1) {
        picture->moveRight();
    } else if (cols == -1) {
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

char Board::getNextBlock() const {
    return nextBlock;
}

Player* Board::getPlayer() {
    return player;
}
