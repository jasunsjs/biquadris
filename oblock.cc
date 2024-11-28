#include "oblock.h"

using namespace std;

OBlock::OBlock(Board *component, int generatedLevel, vector<pair<int, int>> coords, char symbol):
    Decorator{component, generatedLevel, coords, symbol} {}

void OBlock::rotateClockwise() {
    return;
}

void OBlock::rotateCounterClockwise() {
    return;
}

