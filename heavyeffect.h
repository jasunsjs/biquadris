#ifndef HEAVYEFFECT_H
#define HEAVYEFFECT_H
#include "effect.h"

class HeavyEffect : public Effect {
    int numRows = 2;
  public:
    void apply(Board& board) override;
};

#endif
