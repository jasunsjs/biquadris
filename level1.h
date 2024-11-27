#ifndef LEVEL1_H
#define LEVEL1_H
#include "level.h"
#include <unordered_map>
#include <cstdlib>

class Level1 : public Level {
    std::unordered_map<char, double> blockProbabilities;
  public:
    Level1();
    char nextBlock() override;
};

#endif
