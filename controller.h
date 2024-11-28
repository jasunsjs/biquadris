#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "player.h"
#include <unordered_map>
#include <string>

class Controller {
    std::unordered_map<std::string, std::string> commandMap;
    Player* p1, p2, currPlayer;
  public:
    Controller(Player* p1, Player* p2);
    void takeCommand();
    bool interpretCommand(std::string& cmd);
    void processCommand(const std::string& cmd);
    void levelUp();
    void levelDown();
    void restart();
    void switchPlayer();
};

#endif
