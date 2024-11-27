#ifndef LEVEL4_H
#define LEVEL4_H
#include "level.h"
#include <vector>
#include <utility>

class Level4 : public Level {
    std::vector<std::pair<char, int>> blockWeights;
    int totalWeight, numBlocks;
  public:
    Level4();
    char nextBlock() override;
    void rowCleared();
    void blockPlaced();
    bool shouldDropStar();
};

#endif
