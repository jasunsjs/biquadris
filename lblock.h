#ifndef LBLOCK_H
#define LBLOCK_H

#include "decorator.h"

class LBlock: public Decorator {
  public:
    LBlock(Board *component,
           int generatedLevel,
           std::vector<std::pair<int, int>> coords = {{2, 2}, {2, 3}, {1, 3}, {0, 3}}, 
           char symbol = 'L');
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    char charAt(int x, int y) const override;
};

#endif
