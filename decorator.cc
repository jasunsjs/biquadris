#include "decorator.h"

using namespace std;


// ** Decorator Constructor and Destructor **
Decorator::Decorator(Board *component, vector<pair<int, int>> coords, char symbol, 
    int generatedLevel, RotationState state, pair<int, int> bottomLeft):
        component{component}, 
        coords{coords}, 
        symbol{symbol}, 
        generatedLevel{generatedLevel}, 
        state{state}, 
        bottomLeft{bottomLeft} {}

Decorator::~Decorator() {
    delete component;
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

void Decorator::MoveRight() {
    vector<pair<int, int>> newCoords = coords;
    for (int i = 0; i < newCoords.size(); ++i) {
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
        coords[i].second = newCoords[i].second - 1;
    }
    newBottomLeft.second--;

    // Assign
    coords = newCoords;
    bottomLeft = newBottomLeft;
    return true;
}


// ** Helper methods for movement and rotations **
bool Decorator::isValid(const vector<pair<int, int>> &coordinates) const {
    for (pair<int, int> p : coordinates) {
        
        // Check if out of bounds and if position is already occupied
        if (p.first < 0 || p.first >= component->getCols() || p.second < 0 || p.second >= component->getRows() ||
            charAt(p.first, p.second) != ' ') {
            return false;
        }
    }
    return true;
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
