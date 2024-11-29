#include "forceblock.h"
#include <iostream>

ForceBlock::ForceBlock(int generatedLevel, Decorator *component, char symbol):
    Decorator{component, generatedLevel, {std::make_pair(0, getCols()/2)}, symbol} {}

char ForceBlock::charAt(int x, int y) const {
    return '*';
}
