#ifndef LEVEL4_H
#define LEVEL4_H
#include "level.h"
#include <vector>
#include <utility>
#include <string>
#include <fstream>

class Level4 : public Level {
    std::vector<std::pair<char, int>> blockWeights;
    int totalWeight, numBlocks;
    bool random;
    std::ifstream input;
  public:
    Level4();
    char nextBlock() override;
    void rowCleared();
    void blockPlaced();
    bool shouldDropStar();
    void setRandom(bool randBool);
    void setSequenceFile(std::string filename);
};

#endif
