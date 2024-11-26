#include "decorator.h"

using namespace std;

// ** Decorator Constructor and Destructor **
Decorator::Decorator(Board *component, vector<pair<int, int>> coords, char symbol, int generatedLevel):
    component{component}, coords{coords}, symbol{symbol}, generatedLevel{generatedLevel} {}

Decorator::~Decorator() {
    delete component;
}

// ** Universal Block Movement **
void Decorator::moveLeft() {

    // Determine left most cell
    int leftMost = component.getCols() - 1;
    for (pair<int, int> p : coords) {
        if (p.first < leftMost) {
            leftMost = p.first;
        }
    }

    // Check condition for moving left
    if (leftMost != 0 && ) {
        for (pair<int, int> p : coords) {
            p.first--;
        }
    }
}

void Decorator::MoveRight() {
    if (coords.first != component.getCols() - 1) {
        coords.first++;
    }
}

void Decorator::moveDown() {
    if () {
        coords.second--;
    }
}

bool Decorator::drop() {

}

