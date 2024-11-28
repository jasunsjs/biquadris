#include "decorator.h"
#include <iostream>

using namespace std;

// ** Decorator Constructor and Destructor **
Decorator::Decorator(Board *component, int generatedLevel, vector<pair<int, int>> coords, char symbol):
    component{component}, 
    generatedLevel{generatedLevel},
    coords{coords}, 
    symbol{symbol} {}

Decorator::~Decorator() {
    if (component) {
        delete component;
    }
}


// ** Universal Block Movement **
void Decorator::moveLeft() {
    vector<pair<int, int>> newCoords = coords;
    for (int i = 0; i < newCoords.size(); ++i) {
        newCoords[i].first--;
    }

    if (isValid(newCoords)) {
        coords = newCoords;
        bottomLeft.first--;
    }
}

void Decorator::moveRight() {
    vector<pair<int, int>> newCoords = coords;
    for (int i = 0; i < newCoords.size(); ++i) {
        // std::cout << "qwerty" << std::endl;
        newCoords[i].first++;
    }

    if (isValid(newCoords)) {
        
        coords = newCoords;
        bottomLeft.first++;
    }
}

void Decorator::moveDown() {
    vector<pair<int, int>> newCoords = coords;
    for (int i = 0; i < newCoords.size(); ++i) {
        newCoords[i].second++;
    }

    if (isValid(newCoords)) {
        coords = newCoords;
        bottomLeft.second++;
    }
    cout << bottomLeft.first << ", " << bottomLeft.second << endl;
}

bool Decorator::drop() {
    vector<pair<int, int>> newCoords = coords;
    pair<int, int> newBottomLeft = bottomLeft;


    // Continuously move down until invalid position
    while (isValid(newCoords)) {
        for (int i = 0; i < newCoords.size(); ++i) {
            newCoords[i].second++;
        }
        newBottomLeft.second++;
    }

    // Go back by 1 unit
    for (int i = 0; i < coords.size(); ++i) {
        newCoords[i].second--;
    }
    newBottomLeft.second--;

    // Assign
    coords = newCoords;
    bottomLeft = newBottomLeft;
    dropped = true;
    return true;
}


// ** Helper methods for movement and rotations **
bool Decorator::isValid(const vector<pair<int, int>> &coordinates) {
    for (pair<int, int> p : coordinates) {
        
        // Check if out of bounds and if position is already occupied
        if (p.first < 0 || p.first >= component->getCols() || p.second < 0 || p.second >= component->getRows() + 3 ||
            (blockAt(p.first, p.second) && blockAt(p.first, p.second)->dropped)) {
            return false;
        }
    }
    return true;
}

char Decorator::charAt(int x, int y) const {

    // Check if within block
    for (pair<int, int> p : coords) {
        if (p.first == x && p.second == y) {
            return symbol;
        }
    }
    return component->getState(x, y); 
}

Decorator* Decorator::blockAt(int x, int y) {
    for (pair<int, int> p : coords) {
        if (p.first == x && p.second == y) {
            return this;
        }
    }
    return component->getBlock(x, y);
}

void Decorator::transpose(vector<pair<int, int>> &coordinates, pair<int, int> &anchor) const {
    for (int i = 0; i < coordinates.size(); ++i) {
        swap(coordinates[i].first, coordinates[i].second);
    }
    swap(anchor.first, anchor.second);
}

void Decorator::reposition(vector<pair<int, int>> &coordinates, pair<int, int> &anchor) const {
    // Calculate x and y translation factors
    int xDiff = bottomLeft.first - anchor.first;
    int yDiff = bottomLeft.second - anchor.second;

    for (int i = 0; i < coordinates.size(); ++i) {
        coordinates[i].first += xDiff;
        coordinates[i].second += yDiff;
    }
    anchor = bottomLeft;
}
