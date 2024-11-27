#ifndef BLINDEFFECT_H
#define BLINDEFFECT_H
#include "effect.h"

class BlindEffect : public Effect {
    int rowStart, rowEnd, colStart, colEnd;
  public:
    BlindEffect();
    void apply(Board& board) override;
};

#endif
