#ifndef LEVEL3_H
#define LEVEL3_H
#include "level.h"
#include <cstdlib>

class Level3 : public Level {
    std::unordered_map<char, double> blockProbabilities;
  public:
    Level3();
    char nextBlock() override;
};

#endif
