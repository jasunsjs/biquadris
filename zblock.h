#ifndef ZBLOCK_H
#define ZBLOCK_H

#include "decorator.h"

class ZBlock: public Decorator {
  public:
    ZBlock(Board *component, 
           std::vector<std::pair<int, int>> coords = {{0, 2}, {1, 2}, {1, 3}, {2, 3}},
           char symbol = 'Z',
           int generatedLevel);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    char charAt(int x, int y) const override;
};

#endif
