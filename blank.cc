#include "blank.h"

using namespace std;

Blank::Blank(Board *component, vector<pair<int, int>> coords = {}, char symbol = ' ', int generatedLevel):
    Decorator{component, coords, symbol, generatedLevel} {}

char Blank::charAt(int x, int y) const {
    return ' ';
}
