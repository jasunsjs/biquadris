#ifndef DECORATOR_H
#define DECORATOR_H

#include <utility>
#include <vector>
#include "board.h"

enum class RotationState {
    Default,      // Default orientation
    Rotated90,    // Assume clockwise be default
    Rotated180,
    Rotated270
};

class Decorator: public Board {
  protected:
    Board *component;
    std::vector<std::pair<int, int>> coords; // Vector of 4 pairs representing each block cell's position
    char symbol;
    int generatedLevel;
    RotationState state;
    std::pair<int, int> bottomLeft; // Anchor point for rotations
  public:
    Decorator(Board *component, 
              std::vector<std::pair<int, int>> coords, 
              char symbol, 
              int generatedLevel, 
              RotationState state = RotationState::Default, 
              std::pair<int, int> bottomLeft = {0, 3});
    virtual ~Decorator();

    // Universal movement across all blocks
    void moveLeft();
    void MoveRight();
    void moveDown();
    bool drop();

    // Helper methods for movement and rotations
    bool isValid(const std::vector<std::pair<int, int>> &coordinates) const;
    void transpose(std::vector<std::pair<int, int>> &coordinates, 
                   std::pair<int, int> &anchor) const; // Swap x and y values
    void reposition(std::vector<std::pair<int, int>> &coordinates,
                    std::pair<int, int> &anchor) const; // Translate block back to designated anchor point

    // Block specific, pure virtual
    virtual void rotateClockwise() = 0;
    virtual void rotateCounterClockwise() = 0;
    virtual char charAt(int x, int y) const = 0;
};

#endif

