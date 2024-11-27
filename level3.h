#ifndef LEVEL3_H
#define LEVEL3_H
#include "level.h"
#include <vector>
#include <utility>

class Level3 : public Level {
    std::vector<std::pair<char, int>> blockWeights;
    int totalWeight;
  public:
    Level3();
    char nextBlock() override;
};

#endif
