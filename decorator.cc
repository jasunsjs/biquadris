#include "decorator.h"

using namespace std;

// ** Decorator Constructor and Destructor **
Decorator::Decorator(Board *component, vector<pair<int, int>> coords, char symbol, int generatedLevel, RotationState state):
    component{component}, coords{coords}, symbol{symbol}, generatedLevel{generatedLevel}, state{state} {}

Decorator::~Decorator() {
    delete component;
}

// ** Universal Block Movement **
void Decorator::moveLeft() {
    if (canMoveLeft(*this)) {
        for (pair<int, int> p : coords) {
            p.first--;
        }
    }
}

void Decorator::MoveRight() {
    if (canMoveRight(*this)) {
        for (pair<int, int> p : coords) {
            p.first++;
        }
    }
}

void Decorator::moveDown() {
    if (canMoveDown(*this)) {
        for (pair<int, int> p : coords) {
            p.second++;
        }
    }
}

bool Decorator::drop() {
    while (canMoveDown(*this)) {
        this->moveDown();
    }
    return true;
}

std::vector<std::pair<int, int>> Decorator::getCoords() const {
    return coords;
}

Board* Decorator::getComponent() const {
    return component;
}


// ** Helper functions **
bool canMoveLeft(const Decorator &d) {

    // Check if block is at edge of board
    for (pair<int, int> p : d.getCoords()) {
        if (p.first == 0) {
            return false;
        }
    }

    // Check if block has room to move
    for (pair<int, int> p : d.getCoords()) {
        if (d.charAt(p.first - 1, p.second) != ' ') {
            return false;
        }
    }
    return true;
}

bool canMoveRight(const Decorator &d) {

    // Check if block is at edge of board
    for (pair<int, int> p : d.getCoords()) {
        if (p.first == d.getComponent()->getCols() - 1) {
            return false;
        }
    }

    // Check if block has room to move
    for (pair<int, int> p : d.getCoords()) {
        if (d.charAt(p.first + 1, p.second) != ' ') {
            return false;
        }
    }
    return true;
}

bool canMoveDown(const Decorator &d) {

    // Check if block is at edge of board
    for (pair<int, int> p : d.getCoords()) {
        if (p.second == d.getComponent()->getRows() - 1) {
            return false;
        }
    }

    // Check if block has room to move
    for (pair<int, int> p : d.getCoords()) {
        if (d.charAt(p.first, p.second + 1) != ' ') {
            return false;
        }
    }
    return true;
}

