#ifndef FORCEEFFECT_H
#define FORCEEFFECT_H
#include "effect.h"

class ForceEffect : public Effect {
    char blockSelect;
  public:
    ForceEffect(char block);
    void apply(Board& board) override;
};

#endif
