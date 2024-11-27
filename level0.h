#ifndef LEVEL0_H
#define LEVEL0_H
#include "level.h"
#include <fstream>

class Level0 : public Level {
    ifstream input;
  public:
    Level0(string filename);
    ~Level0();
    char nextBlock() override;
};

#endif
