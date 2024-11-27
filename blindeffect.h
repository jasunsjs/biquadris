#ifndef BLINDEFFECT_H
#define BLINDEFFECT_H
#include "effect.h"

class BlindEffect : public Effect {
  public:
    void apply(Board& board) override;
};

#endif