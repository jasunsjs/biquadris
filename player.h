#ifndef PLAYER_H
#define PLAYER_H
#include "effect.h"
#include "board.h"

class Player {
    std::string playerName;
    Effect currEffect;
    int level, score;
    Board* board;
  public:
    void applyEffect();
};  

#endif
