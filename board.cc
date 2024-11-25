#include "board.h"

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
