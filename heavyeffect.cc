#include "heavyeffect.h"
#include "board.h"

void HeavyEffect::apply(Board& board) {
    for (int i = 0; i < numRows; ++i) {
        board.dropBlock();
    }
}
