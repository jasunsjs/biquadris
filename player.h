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
    ifstream inputFile;
  public:
    Player(const std::string& name = "Player");
    void applyEffect();
    void setInputFile(const std::string& filename);
    void setName(const std::string& name);
    void setBoard(Board* b);
};

#endif
