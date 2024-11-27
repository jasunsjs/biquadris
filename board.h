#ifndef BOARD_H
#define BOARD_H
#include "subject.h"

class Decorator; 

class Board : public Subject {
    int rows, cols;
    Decorator* picture;
  public:
    Board();
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
