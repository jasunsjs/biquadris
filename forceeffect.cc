#include "forceeffect.h"
#include "board.h"

ForceEffect::ForceEffect(char block) : blockSelect{block} {}

void ForceEffect::apply(Board& board) {
    board.setBlock(blockSelect);
}
