#ifndef BOARD_H
#define BOARD_H
#include "subject.h"
#include <string>

class Decorator; // Forward declaration
class Player; // Forward declaration

class Board : public Subject {
    int rows = 15;
    int cols = 11;
    Decorator* picture;
    Player* player = nullptr;
    char nextBlock;
  public:
    Board();
    ~Board();
    Board(int row, int col, Decorator *picture);
    char getState(int x, int y) const override;
    Decorator* getBlock(int x, int y);
    void removeLayer();
    void checkBoard();
    int getRows() const;
    int getCols() const;
    void setBlind(int rowStart, int rowEnd, int colStart, int colEnd);
    void setBlock(char block);
    void moveBlock(int rows, int cols);
    void rotateBlock(bool clockwise);
    bool dropBlock();
    int getScore() const;
    int getLevel() const;
    void setNextBlock(char block);
    char getNextBlock() const;
    std::string getPlayerName() const;
    void setPlayer(Player* p);
};

#endif
