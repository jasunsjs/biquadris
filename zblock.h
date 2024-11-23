#ifndef ZBLOCK_H
#define ZBLOCK_H

#include "decorator.h"

class ZBlock: public Decorator {
  public:
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    char charAt(int x, int y) override;
};

#endif
