#ifndef LEVEL_H
#define LEVEL_H

class Level {
    int levelNum;
  public:
    Level(int num) : levelNum{num} {}
    virtual char nextBlock() = 0;
    virtual ~Level() = default;
};

#endif
