#include "tblock.h"

using namespace std;


void TBlock::rotateClockwise() {
    vector<pair<int, int>> newCoords = coords;
    pair<int, int> newBottomLeft = bottomLeft;

    transpose(newCoords, newBottomLeft);
    
    // Set new bottom left anchor and reverse cols
    if (state == RotationState::Default || state == RotationState::Rotated270) {
        newBottomLeft.first -= 1;
        newBottomLeft.second += 2;

        newCoords[0].first = newCoords[3].first;
        newCoords[2].first = newCoords[3].first;
        swap(newCoords[1], newCoords[3]);
    } else {
        newBottomLeft.first -= 2;
        newBottomLeft.second += 1;
    }

    reposition(newCoords, newBottomLeft);

    if (isValid(newCoords)) {
        coords = newCoords;
    }

    // Change state
    state = static_cast<RotationState>((static_cast<int>(state) + 1) % 4);
}

void TBlock::rotateCounterClockwise() {
    for (int i = 0; i < 3; ++i) {
        rotateClockwise();
    }
}

char TBlock::charAt(int x, int y) const {

    // Check if within block
    for (pair<int, int> p : coords) {
        if (p.first == x && p.second == y) {
            return symbol;
        }
    }

    // Else call next decorator's charAt()
    return component->getState(x, y);
}
