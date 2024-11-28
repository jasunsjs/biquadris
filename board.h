#ifndef BOARD_H
#define BOARD_H
#include "subject.h"
// #include "player.h"

class Decorator; 

class Board : public Subject {
    int rows, cols;
    Decorator* picture;
    // Player* owner;

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

    int getScore() const { return 0; }
    int getLevel() const { return 1; }
  
    //char getNextBlock() const { return owner->getNextBlock(); }
    char getNextBlock() const { return 'J'; }
};

#endif
