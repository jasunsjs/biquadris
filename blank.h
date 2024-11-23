#ifndef BLANK_H
#define BLANK_H

#include "decorator.h"

class Blank: public Decorator {
  public:
    char charAt(int x, int y) override;
};

#endif
