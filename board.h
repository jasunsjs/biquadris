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
    void removeLayer(int row);
    void checkBoard();
    int getRows() const;
    int getCols() const;
    void setBlind(int rowStart, int rowEnd, int colStart, int colEnd);
    bool setBlock(char block);
    void replaceBlock(char block);
    void moveBlock(int rows, int cols);
    void rotateBlock(bool clockwise);
    void dropBlock();
    int getScore() const;
    int getLevel() const;
    void setNextBlock(char block);
    char getNextBlock() const;
    std::string getPlayerName() const;
    void setPlayer(Player* p);
};

#endif
