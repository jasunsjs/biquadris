#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <fstream>
#include <unordered_map>
#include <string>
#include <iostream>

class Controller {
    std::unordered_map<std::string, std::string> commandMap;
    bool noRandom1, noRandom2;
    Player* p1, p2;
  public:
    Controller();
    void levelUp();
    void levelDown();
    void restart();
};

#endif
