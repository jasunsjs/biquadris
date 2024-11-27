#ifndef EFFECT_H
#define EFFECT_H
#include "board.h"

class Effect {
  public:
    virtual ~Effect() = default;
    virtual void apply(Board& board) = 0;
};

#endif
