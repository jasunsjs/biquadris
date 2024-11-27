#include "heavyeffect.h"

HeavyEffect::HeavyEffect() : numRows{2} {}

void HeavyEffect::apply(Board& board) {
    for (int i = 0; i < numRows; ++i) {
        board.dropBlock();
    }
}
