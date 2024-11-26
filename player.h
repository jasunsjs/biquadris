#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "effect.h"
#include "board.h"

class Player {
    std::string playerName;
    Effect currEffect;
    int level, score;
    Board* board;
  public:
    Player(const std::string& name);
    void applyEffect();
};

#endif
