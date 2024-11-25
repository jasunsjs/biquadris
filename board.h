#ifndef BOARD_H
#define BOARD_H
#include "decorator.h"

class Board {
    int width, height;
    Decorator* picture;
  public:
    char getState(int x, int y) const override;
    void removeLayer();
    void checkBoard();
};

#endif
