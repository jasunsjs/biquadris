#ifndef PLAYER_H
#define PLAYER_H
#include "effect.h"
#include "board.h"

class Player {
    string playerName;
    Effect currEffect;
    int level;
    int score;
    Board* board;
  public:
    void applyEffect();
};  

#endif
