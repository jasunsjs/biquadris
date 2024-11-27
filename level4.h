#ifndef LEVEL4_H
#define LEVEL4_H
#include "level.h"
#include <cstdlib>

class Level4 : public Level {
    std::unordered_map<char, double> blockProbabilities;
    int numBlocks;
  public:
    Level4();
    char nextBlock() override;
};

#endif
