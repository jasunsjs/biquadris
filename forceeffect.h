#ifndef FORCEEFFECT_H
#define FORCEEFFECT_H
#include "effect.h"

class ForceEffect : public Effect {
  public:
    void apply(Board& board) override;
};

#endif