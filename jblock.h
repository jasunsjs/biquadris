#ifndef JBLOCK_H
#define JBLOCK_H

#include "decorator.h"

class JBlock: public Decorator {
  public:
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    char charAt(int x, int y) const override;
};

#endif
