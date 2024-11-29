#include "zblock.h"

using namespace std;


ZBlock::ZBlock(Decorator *component, int generatedLevel, vector<pair<int, int>> coords, char symbol):
    Decorator{component, generatedLevel, coords, symbol} {}

void ZBlock::rotateClockwise() {
    vector<pair<int, int>> newCoords = coords;
    pair<int, int> newBottomLeft = bottomLeft;

    transpose(newCoords, newBottomLeft);
    
    // Set new bottom left anchor and reverse cols
    if (state == RotationState::Default) {
        newBottomLeft.first -= 1;
        newBottomLeft.second += 2;

        newCoords[0].first = newCoords[2].first;
        newCoords[3].first = newCoords[1].first;

        // Change state
        state = RotationState::Rotated90;
    } else {
        newBottomLeft.first -= 2;
        newBottomLeft.second += 1;

        newCoords[0].second = newCoords[1].second;
        newCoords[3].second = newCoords[2].second;

        // Change state
        state = RotationState::Default; 
    }

    reposition(newCoords, newBottomLeft);

    if (isValid(newCoords)) {
        coords = newCoords;
    }
}

void ZBlock::rotateCounterClockwise() {
    rotateClockwise();
}

