#ifndef ZBLOCK_H
#define ZBLOCK_H

#include "decorator.h"

class ZBlock: public Decorator {
  public:
    ZBlock(Board *component,
           int generatedLevel,
           std::vector<std::pair<int, int>> coords = {{0, 2}, {1, 2}, {1, 3}, {2, 3}},
           char symbol = 'Z');
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    char charAt(int x, int y) const override;
};

#endif
