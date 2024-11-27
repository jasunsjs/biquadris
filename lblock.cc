#include "lblock.h"

using namespace std;

void LBlock::rotateClockwise() {

    if (state == RotationState::Default) {
        for ()
    }
    state = static_cast<RotationState>((static_cast<int>(state) + 1) % 4);

    return;
}

void LBlock::rotateCounterClockwise() {
    state = static_cast<RotationState>((static_cast<int>(state) + 3) % 4);

    return;
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


