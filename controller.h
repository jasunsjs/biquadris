#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "player.h"
#include <unordered_map>
#include <string>

class Controller {
    std::unordered_map<std::string, std::string> commandMap;
    Player *p1, *p2, *currPlayer;
  public:
    Controller(Player* p1, Player* p2);
    bool takeCommand();
    bool interpretCommand(std::string& cmd);
    bool processCommand(const std::string& cmd);
    void render();
    void levelUp();
    void levelDown();
    void switchPlayer();
    void generateNextBlock(Player* p);
    void generateCurrBlock(Player* p);
};

#endif
