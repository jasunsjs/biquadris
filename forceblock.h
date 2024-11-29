#ifndef FORCEBLOCK_H
#define FORCEBLOCK_H

#include "decorator.h"

class ForceBlock: public Decorator {
  public:
    ForceBlock(int generatedLevel, Decorator *component = nullptr, char symbol = '*');
    char charAt(int x, int y) const override;
};

#endif
