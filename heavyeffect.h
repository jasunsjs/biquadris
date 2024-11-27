#ifndef HEAVYEFFECT_H
#define HEAVYEFFECT_H
#include "effect.h"

class HeavyEffect : public Effect {
    int numRows;
  public:
    HeavyEffect();
    void apply(Board& board) override;
};

#endif
