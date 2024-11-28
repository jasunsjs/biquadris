#ifndef SBLOCK_H
#define SBLOCK_H

#include "decorator.h"

class SBlock: public Decorator {
  public:
    SBlock(Board *component, 
           int generatedLevel,
           std::vector<std::pair<int, int>> coords = {{1, 2}, {2, 2}, {0, 3}, {1, 3}},
           char symbol = 'S');
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    char charAt(int x, int y) const override;
};

#endif
