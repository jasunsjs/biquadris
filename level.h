#ifndef LEVEL_H
#define LEVEL_H

class Level {
  public:
    virtual char nextBlock() = 0;
    virtual ~Level() = default;
};

#endif
