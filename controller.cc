#include "controller.h"
#include "level3.h"
#include "level4.h"
#include "effect.h"
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
    // effectMap = {
    //     {"b", "blind"},
    //     {"bl", "blind"},
    //     {"bli", "blind"},
    //     {"blin", "blind"},
    //     {"blind", "blind"},
    //     {"h", "heavy"},
    //     {"he", "heavy"},
    //     {"hea", "heavy"},
    //     {"heav", "heavy"},
    //     {"heavy", "heavy"},
    //     {"f", "force"},
    //     {"fo", "force"},
    //     {"for", "force"},
    //     {"forc", "force"},
    //     {"force", "force"}
    // }
}

bool Controller::takeCommand() {
    // Get command from input, interpret, then process command
    std::string cmd;
    int multiplier = 1;
    std::cout << "Player " << currPlayer->getName() << ", please enter command:" << std::endl;
    while (std::cin >> cmd) {
        if (interpretCommand(cmd, multiplier)) {
            break;
        }
    }
    if (std::cin.eof()) {
        return false;
    }
    return processCommand(cmd, multiplier);
}

bool Controller::interpretCommand(std::string& cmd, int& multiplier) {
    // Check for multiplier prefix
    std::string numStr = "";
    int i = 0;
    while (i < cmd.length() && '0' <= cmd[i] && cmd[i] <= '9') {
        numStr += cmd[i];
        ++i;
    }
    std::istringstream iss{numStr};
    int mult = 1;
    iss >> mult;
    if (mult <= 0) {
        std::cout << "Invalid multiplier prefix" << std::endl;
        return false;
    }
    multiplier = mult;
    cmd = cmd.substr(i);
    // Find corresponding command in map
    auto found = commandMap.find(cmd);
    if (found != commandMap.end()) {
        cmd = found->second;
        return true;
    }
    std::cout << "Invalid command" << std::endl;
    return false;
}

bool Controller::processCommand(const std::string& cmd, int multiplier) {
    // Carry out command multiplier times
    for (int i = 0; i < multiplier; ++i) {
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
            // Check for special action
            if (currPlayer->getBoard()->checkBoard() >= 2) {
                render();
                takeSpecialAction();
            }
            if (!generateCurrBlock(currPlayer)) {
                render();
                return false;
            }
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
            } else {
                std::string sequenceFilename;
                std::cin >> sequenceFilename;
                // Casting to appropriate level
                if (auto* level3 = dynamic_cast<Level3*>(currPlayer->getLevel())) {
                    level3->setRandom(false);
                    level3->setSequenceFile(sequenceFilename);
                } else if (auto* level4 = dynamic_cast<Level4*>(currPlayer->getLevel())) {
                    level4->setRandom(false);
                    level4->setSequenceFile(sequenceFilename);
                }
            }
        } else if (cmd == "random") {
            if (currPlayer->getLevel()->getLevelNum() != 3 && currPlayer->getLevel()->getLevelNum() != 4) {
                std::cout << "This command only works on levels 3 and 4" << std::endl;
            } else {
                // Casting to appropriate level
                if (auto* level3 = dynamic_cast<Level3*>(currPlayer->getLevel())) {
                    level3->setRandom(true);
                } else if (auto* level4 = dynamic_cast<Level4*>(currPlayer->getLevel())) {
                    level4->setRandom(true);
                }
            }
        } else if (cmd == "sequence") {
            std::string sequenceFilename;
            std::cin >> sequenceFilename;
            std::ifstream input{sequenceFilename};
            std::string line, str;
            int multiplier = 1;
            while (getline(input, line)) {
                std::istringstream iss{line};
                while (iss >> str) {
                    if (interpretCommand(str, multiplier)) {
                        processCommand(str, multiplier);
                    }
                }
            }
        } else if (cmd == "I") {
            currPlayer->getBoard()->replaceBlock('I');
        } else if (cmd == "J") {
            currPlayer->getBoard()->replaceBlock('J');
        } else if (cmd == "L") {
            currPlayer->getBoard()->replaceBlock('L');
        } else if (cmd == "O") {
            currPlayer->getBoard()->replaceBlock('O');
        } else if (cmd == "S") {
            currPlayer->getBoard()->replaceBlock('S');
        } else if (cmd == "Z") {
            currPlayer->getBoard()->replaceBlock('Z');
        } else if (cmd == "T") {
            currPlayer->getBoard()->replaceBlock('T');
        }
    }
    // Render displays
    render();
    return true;
}

void Controller::takeSpecialAction() {
    std::string action;
    char cmd;
    while (true) {
        std::cout << "Select special action (b - blind, h - heavy, f - force): ";
        getline(std::cin, action);
        if (std::cin.eof()) {
            return;
        }
        if (action == "b" || action == "h" || action == "f") {
            cmd = action[0];
            break;
        }
    }
    Player* targetPlayer = (currPlayer == p1) ? p2 : p1;
    switch(cmd) {
        case 'b':
            targetPlayer->setEffect(Effect::BLIND);
            break;
        case 'h':
            targetPlayer->setEffect(Effect::HEAVY);
            break;
        case 'f':
            targetPlayer->setEffect(Effect::FORCE);
            break;
    }
}

void Controller::render() {
    currPlayer->getBoard()->updateObservers();
}

void Controller::levelUp() {
    if (currPlayer->getLevel()->getLevelNum() == 4) {
        std::cout << "Cannot increase level, already at highest level" << std::endl;
    } else {
        int newLevel = currPlayer->getLevel()->getLevelNum() + 1;
        std::cout << "Increasing player " << currPlayer->getName() << " level to " << newLevel << std::endl;
        currPlayer->setLevel(newLevel);
    }
}

void Controller::levelDown() {
    if (currPlayer->getLevel()->getLevelNum() == 0) {
        std::cout << "Cannot decrease level, already at lowest level" << std::endl;
    } else {
        int newLevel = currPlayer->getLevel()->getLevelNum() - 1;
        std::cout << "Decreasing player " << currPlayer->getName() << " level to " << newLevel << std::endl;
        currPlayer->setLevel(newLevel);
    }
}

void Controller::switchPlayer() {
    currPlayer->setEffect(Effect::NONE);
    currPlayer = (currPlayer == p1) ? p2 : p1;
}

void Controller::generateNextBlock(Player* p) {
    char block = p->getLevel()->nextBlock();
    p->getBoard()->setNextBlock(block);
}

bool Controller::generateCurrBlock(Player* p) {
    if (!p->getBoard()->setBlock(p->getBoard()->getNextBlock())) {
        return false;
    }
    generateNextBlock(p);
    return true;
}
