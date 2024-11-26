#ifndef SBLOCK_H
#define SBLOCK_H

#include "decorator.h"

class SBlock: public Decorator {
  public:
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    char charAt(int x, int y) override;
};

#endif
