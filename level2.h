#ifndef LEVEL2_H
#define LEVEL2_H
#include "level.h"
#include <cstdlib>

class Level2 : public Level {
    std::unordered_map<char, double> blockProbabilities;
  public:
    Level2();
    char nextBlock() override;
};

#endif
