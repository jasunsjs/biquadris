#ifndef HEAVYEFFECT_H
#define HEAVYEFFECT_H
#include "effect.h"

class HeavyEffect : public Effect {
  public:
    void apply(Board& board) override;
};

#endif