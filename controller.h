#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <fstream>
#include <unordered_map>
#include <string>

class Controller {
    std::unordered_map<std::string, std::string> commandMap;
    bool noRandom1, noRandom2;
    std::ifstream inputFile1, inputFile2;
  public:
    Controller();
    void levelUp();
    void levelDown();
    void restart();
};

#endif
