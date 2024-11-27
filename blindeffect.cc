#include "blindeffect.h"

BlindEffect::BlindEffect() : rowStart{3}, rowEnd{12}, colStart{3}, colEnd{9} {}

void BlindEffect::apply(Board& board) {
    board.setBlind(rowStart, rowEnd, colStart, colEnd);
}
