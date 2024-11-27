#ifndef DECORATOR_H
#define DECORATOR_H

#include <utility>
#include <vector>
#include "board.h"

class Decorator: public Board {
  protected:
    Board *component;
    std::vector<std::pair<int, int>> coords; // Vector of 4 pairs representing each block cell's position
    char symbol;
    int generatedLevel;
  public:
    Decorator(Board *component, std::vector<std::pair<int, int>> coords, char symbol, int generatedLevel);
    virtual ~Decorator();

    // Universal movement across all blocks
    void moveLeft();
    void MoveRight();
    void moveDown();
    bool drop();

    // Getter
    std::vector<std::pair<int, int>> getCoords() const;
    Board* getComponent() const;

    // Block specific, pure virtual
    virtual void rotateClockwise() = 0;
    virtual void rotateCounterClockwise() = 0;
    virtual char charAt(int x, int y) const = 0;
};

#endif

