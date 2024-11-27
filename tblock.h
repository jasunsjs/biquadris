#ifndef TBLOCK_H
#define TBLOCK_H

#include "decorator.h"

class TBlock: public Decorator {
  public:
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    char charAt(int x, int y) const override;
};

#endif
