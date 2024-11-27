#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "effect.h"
#include "board.h"

class Player {
    std::string playerName, inputFilename;
    Effect currEffect;
    int level, score;
    Board* board;
  public:
    Player(const std::string& name = "Player", Board* b, const std::string& filename);
    void applyEffect();
    void setLevel(int lvl);
    std::string getName();
    int getLevel();
    int getScore();
};

#endif
