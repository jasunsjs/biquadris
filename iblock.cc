#include "iblock.h"

using namespace std;

IBlock::IBlock(Decorator *component, int generatedLevel, vector<pair<int, int>> coords, char symbol):
    Decorator{component, generatedLevel, coords, symbol} {}

void IBlock::rotateClockwise() {
    vector<pair<int, int>> newCoords = coords;
    pair<int, int> newBottomLeft = bottomLeft;

    transpose(newCoords, newBottomLeft);
    
    // Set new bottom left anchor and reverse cols
    if (state == RotationState::Default) {
        newBottomLeft.second += 3;
    } else {
        newBottomLeft.first -= 3;
    }

    reposition(newCoords, newBottomLeft);

    if (isValid(newCoords)) {
        coords = newCoords;

        // Change state
        if (state == RotationState::Default) {
            state = RotationState::Rotated90;
        } else {
            state = RotationState::Default;
        }
    }
}

void IBlock::rotateCounterClockwise() {
    rotateClockwise();
}
