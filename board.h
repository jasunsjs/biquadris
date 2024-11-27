#ifndef BOARD_H
#define BOARD_H
#include "decorator.h"
#include "subject.h"

class Board : public Subject {
    int rows, cols;
    Decorator* picture;
  public:
    Board(int rows = 15, int cols = 11, Decorator* picture);
    char getState(int x, int y) const override;
    void removeLayer();
    void checkBoard();
    int getRows() const;
    int getCols() const;
    void setBlind(int rowStart, int rowEnd, int colStart, int colEnd);
    void setBlock(char block);
    bool dropBlock();
};

#endif
