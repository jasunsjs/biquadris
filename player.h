#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "effect.h"
#include "board.h"
#include "level.h"

class Player {
    std::string playerName, inputFilename;
    Effect* currEffect = nullptr;
    int score = 0;
    Board* board;
    Level* level;
  public:
    Player(const std::string& name, Board* b, const std::string& filename, int startLevel);
    void applyEffect();
    void setLevel(int levelNum);
    std::string getName();
    Level* getLevel() const;
    int getScore() const;
    Board* getBoard() const;
};

#endif
