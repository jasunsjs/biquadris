#include "controller.h"
#include <iostream>
#include <fstream>
#include <sstream>

Controller::Controller(Player* p1, Player* p2) : p1{p1}, p2{p2}, currPlayer{p1} {
    // Create command map with shortcuts
    commandMap = {
        {"lef", "left"},
        {"left", "left"},
        {"ri", "right"},
        {"rig", "right"},
        {"righ", "right"},
        {"right", "right"},
        {"do", "down"},
        {"dow", "down"},
        {"down", "down"},
        {"cl", "clockwise"},
        {"clo", "clockwise"},
        {"cloc", "clockwise"},
        {"clock", "clockwise"},
        {"clockw", "clockwise"},
        {"clockwi", "clockwise"},
        {"clockwis", "clockwise"},
        {"clockwise", "clockwise"},
        {"co", "counterclockwise"},
        {"cou", "counterclockwise"},
        {"coun", "counterclockwise"},
        {"count", "counterclockwise"},
        {"counte", "counterclockwise"},
        {"counter", "counterclockwise"},
        {"counterc", "counterclockwise"},
        {"countercl", "counterclockwise"},
        {"counterclo", "counterclockwise"},
        {"countercloc", "counterclockwise"},
        {"counterclock", "counterclockwise"},
        {"counterclockw", "counterclockwise"},
        {"counterclockwi", "counterclockwise"},
        {"counterclockwis", "counterclockwise"},
        {"counterclockwise", "counterclockwise"},
        {"d", "drop"},
        {"dr", "drop"},
        {"dro", "drop"},
        {"drop", "drop"},
        {"levelu", "levelup"},
        {"levelup", "levelup"},
        {"leveld", "levelup"},
        {"leveldo", "levelup"},
        {"leveldow", "levelup"},
        {"leveldown", "leveldown"},
        {"re", "restart"},
        {"res", "restart"},
        {"rest", "restart"},
        {"resta", "restart"},
        {"restar", "restart"},
        {"restart", "restart"},
        {"n", "norandom"},
        {"no", "norandom"},
        {"nor", "norandom"},
        {"nora", "norandom"},
        {"noran", "norandom"},
        {"norand", "norandom"},
        {"norando", "norandom"},
        {"norandom", "norandom"},
        {"ra", "random"},
        {"ran", "random"},
        {"rand", "random"},
        {"rando", "random"},
        {"random", "random"},
        {"s", "sequence"},
        {"se", "sequence"},
        {"seq", "sequence"},
        {"sequ", "sequence"},
        {"seque", "sequence"},
        {"sequen", "sequence"},
        {"sequenc", "sequence"},
        {"sequence", "sequence"},
        {"I", "I"},
        {"J", "J"},
        {"L", "L"},
        {"O", "O"},
        {"S", "S"},
        {"Z", "Z"},
        {"T", "T"}
    };
}

bool Controller::takeCommand() {
    // Get command from input, interpret, then process command
    string cmd;
    while (true) {
        std::cout << "Player " << currPlayer->getName() << ", please enter command:" << std::endl;
        std::cin >> cmd;
        if (interpretCommand(cmd)) {
            break;
        }
    }
    return processCommand(cmd);
}

bool Controller::interpretCommand(std::string& cmd) {
    // Find corresponding command in map
    auto found = commandMap.find(cmd);
    if (found != commandMap.end()) {
        cmd = found->second;
        return true;
    }
    std::cout << "Invalid command" << std::endl;
    return false;
}

bool Controller::processCommand(const std::string& cmd) {
    // Carry out command
    if (cmd == "left") {
        currPlayer->getBoard()->moveBlock(-1, 0);
    } else if (cmd == "right") {
        currPlayer->getBoard()->moveBlock(1, 0);
    } else if (cmd == "down") {
        currPlayer->getBoard()->moveBlock(0, 1);
    } else if (cmd == "clockwise") {
        currPlayer->getBoard()->rotateBlock(true);
    } else if (cmd == "counterclockwise") {
        currPlayer->getBoard()->rotateBlock(false);
    } else if (cmd == "drop") {
        currPlayer->getBoard()->dropBlock();
        switchPlayer();
    } else if (cmd == "levelup") {
        levelUp();
    } else if (cmd == "leveldown") {
        levelDown();
    } else if (cmd == "restart") {
        return false;
    } else if (cmd == "norandom") {
        if (currPlayer->getLevel()->getLevelNum() != 3 && currPlayer->getLevel()->getLevelNum() != 4) {
            std::cout << "This command only works on levels 3 and 4" << std::endl;
            break;
        }
        string sequenceFilename;
        std::cin >> sequenceFilename;
        currPlayer->getLevel()->setRandom(false);
        currPlayer->getLevel()->setSequenceFile(sequenceFilename);
    } else if (cmd == "random") {
        if (currPlayer->getLevel()->getLevelNum() != 3 && currPlayer->getLevel()->getLevelNum() != 4) {
            std::cout << "This command only works on levels 3 and 4" << std::endl;
            break;
        }
        currPlayer->getLevel()->setRandom(true);
    } else if (cmd == "sequence") {
        string sequenceFilename;
        std::cin >> sequenceFilename;
        ifstream input{sequenceFilename};
        string line, str;
        while (getline(input, line)) {
            istringstream iss{line};
            while (iss >> str) {
                if (interpretCommand(str)) {
                    processCommand(str);
                }
            }
        }
    } else if (cmd == "I") {
        currPlayer->getBoard()->setBlock('I');
    } else if (cmd == "J") {
        currPlayer->getBoard()->setBlock('J');
    } else if (cmd == "L") {
        currPlayer->getBoard()->setBlock('L');
    } else if (cmd == "O") {
        currPlayer->getBoard()->setBlock('O');
    } else if (cmd == "S") {
        currPlayer->getBoard()->setBlock('S');
    } else if (cmd == "Z") {
        currPlayer->getBoard()->setBlock('Z');
    } else if (cmd == "T") {
        currPlayer->getBoard()->setBlock('T');
    }
    // Render displays
    currPlayer->getBoard()->updateObservers();
    return true;
}

void Controller::levelUp() {
    if (currPlayer->getLevel->getLevelNum() == 4) {
        std::cout << "Cannot increase level, already at highest level" << std::endl;
    } else {
        int newLevel = currPlayer->getLevel->getLevelNum() + 1;
        std::cout << "Increasing player " << currPlayer->getName() << " level to " << newLevel << std::endl;
        currPlayer->setLevel(newLevel);
    }
}

void Controller::levelDown() {
    if (currPlayer->getLevel->getLevelNum() == 0) {
        std::cout << "Cannot decrease level, already at lowest level" << std::endl;
    } else {
        int newLevel = currPlayer->getLevel->getLevelNum() - 1;
        std::cout << "Decreasing player " << currPlayer->getName() << " level to " << newLevel << std::endl;
        currPlayer->setLevel(newLevel);
    }
}

void Controller::switchPlayer() {
    if (currPlayer == p1) {
        currPlayer = p2;
    } else {
        currPlayer = p1;
    }
}

void Controller::generateNextBlock(Player* p) {
    char block = p->getLevel()->nextBlock();
    p->getBoard()->setNextBlock(block);
}

void generateCurrBlock(Player* p) {
    p->getBoard()->setBlock(p->getBoard()->getNextBlock());
    generateNextBlock(p);
}
