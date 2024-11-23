#ifndef IBLOCK_H
#define IBLOCK_H

#include "decorator.h"

class IBlock: public Decorator {
  public:
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    char charAt(int x, int y) override;
};

#endif
