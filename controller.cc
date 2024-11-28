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

void Controller::takeCommand() {
    // Get command from input, interpret, then process command
    string cmd;
    while (true) {
        std::cout << "Player " << currPlayer->getName() << ", please enter command:" << std::endl;
        std::cin >> cmd;
        if (interpretCommand(cmd)) {
            break;
        }
    }
    processCommand(cmd);
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

void Controller::processCommand(const std::string& cmd) {
    // Carry out command
    switch (cmd) {
        case "left":
            currPlayer->moveBlock(-1, 0);
            break;
        case "right":
            currPlayer->moveBlock(1, 0);
            break;
        case "down":
            currPlayer->moveBlock(0, 1);
            break;
        case "clockwise":
            currPlayer->rotateBlock(true);
            break;
        case "counterclockwise":
            currPlayer->rotateBlock(true);
            break;
        case "drop":
            currPlayer->dropBlock();
            switchPlayer();
            break;
        case "levelup":
            levelUp();
            break;
        case "leveldown":
            levelDown();
            break;
        case "restart":
            restart();
            break;
        case "norandom":
            if (currPlayer->getLevel()->getLevelNum() != 3 && currPlayer->getLevel()->getLevelNum() != 4) {
                std::cout << "This command only works on levels 3 and 4" << std::endl;
                break;
            }
            string filename;
            std::cin >> filename;
            currPlayer->getLevel()->setRandom(false);
            currPlayer->getLevel()->setSequenceFile(filename);
            break;
        case "random":
            if (currPlayer->getLevel()->getLevelNum() != 3 && currPlayer->getLevel()->getLevelNum() != 4) {
                std::cout << "This command only works on levels 3 and 4" << std::endl;
                break;
            }
            currPlayer->getLevel()->setRandom(true);
            break;
        case "sequence":
            string filename;
            std::cin >> filename;
            ifstream input{filename};
            string line, str;
            while (getLine(input, line)) {
                istringstream iss{line};
                while (iss >> str) {
                    if (interpretCommand(str)) {
                        processCommand(str);
                    }
                }
            }
            break;
        case "I":
            currPlayer->setBlock('I');
            break;
        case "J":
            currPlayer->setBlock('J');
            break;
        case "L":
            currPlayer->setBlock('L');
            break;
        case "O":
            currPlayer->setBlock('O');
            break;
        case "S":
            currPlayer->setBlock('S');
            break;
        case "Z":
            currPlayer->setBlock('Z');
            break;
        case "T":
            currPlayer->setBlock('T');
            break;
    }
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

void Controller::restart() {
    // TODO
}

void Controller::switchPlayer() {
    if (currPlayer == p1) {
        currPlayer = p2;
    } else {
        currPlayer = p1;
    }
}
