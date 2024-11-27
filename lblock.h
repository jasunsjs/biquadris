#ifndef LBLOCK_H
#define LBLOCK_H

#include "decorator.h"

class LBlock: public Decorator {
  public:
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    char charAt(int x, int y) const override;
};

#endif
