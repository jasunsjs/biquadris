#ifndef OBLOCK_H
#define OBLOCK_H

#include "decorator.h"

class OBlock: public Decorator {
  public:
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    char charAt(int x, int y) override;
};

#endif
