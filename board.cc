#include "board.h"

Board::Board(int rows, int cols, Decorator* picture) : rows{rows}, cols{cols}, picture{picture} {}

char Board::getState(int x, int y) const {
    return picture->charAt(x, y);
}

void Board::removeLayer() {
    // TODO
}

void Board::checkBoard() {
    // TODO
}

Board::~Board() { delete picture; }
