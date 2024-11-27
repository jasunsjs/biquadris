#include "lblock.h"

using namespace std;


void LBlock::rotateClockwise() {
    vector<pair<int, int>> newCoords = coords;
    pair<int, int> newBottomLeft = bottomLeft;

    transpose(newCoords, newBottomLeft);
    
    // Set new bottom left anchor and reverse cols
    if (state == RotationState::Default || state == RotationState::Rotated270) {
        newBottomLeft.first -= 1;
        newBottomLeft.second += 2;

        newCoords[2].first = newCoords[0].first;
        newCoords[3].first = newCoords[0].first;
        swap(newCoords[0], newCoords[1]);    
    } else {
        newBottomLeft.first -= 2;
        newBottomLeft.second += 1;

        newCoords[0].first = newCoords[3].first;
        swap(newCoords[1], newCoords[3]);
    }

    reposition(newCoords, newBottomLeft);

    if (isValid(newCoords)) {
        coords = newCoords;
    }

    // Change state
    state = static_cast<RotationState>((static_cast<int>(state) + 1) % 4);
}

void LBlock::rotateCounterClockwise() {
    vector<pair<int, int>> newCoords = coords;
    pair<int, int> newBottomLeft = bottomLeft;

    transpose(newCoords, newBottomLeft);

    // Set new bottom left anchor and reverse rows
    if (state == RotationState::Default || state == RotationState::Rotated270) {
        newBottomLeft.first -= 1;
        newBottomLeft.second += 2;

        newCoords[0].second = newCoords[3].second;
        swap(newCoords[1], newCoords[3]);
    } else {
        newBottomLeft.first -= 2;
        newBottomLeft.second += 1;

        newCoords[2].second = newCoords[0].second;
        newCoords[3].second = newCoords[0].second;
        swap(newCoords[0], newCoords[1]);
    }

    reposition(newCoords, newBottomLeft);

    if (isValid(newCoords)) {
        coords = newCoords;
    }

    // Change state
    state = static_cast<RotationState>((static_cast<int>(state) + 3) % 4);
}

char LBlock::charAt(int x, int y) const {

    // Check if within block
    for (pair<int, int> p : coords) {
        if (p.first == x && p.second == y) {
            return symbol;
        }
    }

    // Else call next decorator's charAt()
    return component->getState(x, y);
}
