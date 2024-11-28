#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "effect.h"
#include "board.h"
#include "level.h"

class Player {
    std::string playerName, inputFilename;
    Effect* currEffect;
    int score;
    Board* board;
    Level* level;
  public:
    Player(const std::string& name = "Player", Board* b, const std::string& filename, int startLevel);
    void applyEffect();
    void setLevel(int levelNum);
    std::string getName();
    Level* getLevel() const;
    int getScore();
    Board* getBoard() const;
};

#endif
