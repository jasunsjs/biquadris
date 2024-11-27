#include "player.h"
#include "board.h"
#include "controller.h"
#include "decorator.h"
#include "observer.h"
#include "textobserver.h"
#include "graphicsobserver.h"
#include <string>
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    std::string scriptFile1 = "sequence1.txt";
    std::string scriptFile2 = "sequence2.txt";
    int highScore = 0;
    std::string highScoreName;
    bool textOnly = false;
    int seed = 0;
    int startLevel = 0;

    // Parse command line args
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-text") {
            textOnly = true;
        } else if (arg == "-seed") {
            // Convert string to int
            std::istringstream iss{argv[++i]};
            iss >> seed;
        } else if (arg == "-scriptfile1") {
            scriptFile1 = argv[++i];
        } else if (arg == "-scriptfile2") {
            scriptFile2 = argv[++i];
        } else if (arg == "-startlevel") {
            startLevel = argv[++i];
        }
    }
    // Set seed
    srand(seed);

    // Set up players and controller
    Board board1{11, 15, new Blank()};
    Board board2{11, 15, new Blank()};
    std::string name;
    std::cout << "Enter Player 1 name: ";
    std::getline(std::cin, name);
    Player p1{name, &board1, scriptFile1};
    p1.setName(name);
    std::cout << "Enter Player 2 name: ";
    std::getline(std::cin, name);
    Player p2{name, &board2, scriptFile2};

    // Set up observers
    TextObserver to1{&board1, 11, 15, std::cout};
    TextObserver to2{&board2, 11, 15, std::cout};
    board1.attach(&to1);
    board2.attach(&to2);
    if (!textOnly) {
        GraphicsObserver go1{&board1, 11, 15};
        GraphicsObserver go2{&board2, 11, 15};
        board1.attach(&go1);
        board2.attach(&go2);
    } 

    Controller ctrl{&p1, &p2};
    // Main game loop
    // TODO
}
