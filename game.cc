#include "player.h"
#include "board.h"
#include "controller.h"
#include "decorator.h"
#include "observer.h"
#include "textobserver.h"
#include "graphicsobserver.h"
#include "blank.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>

const int BOARD_ROWS = 15;
const int BOARD_COLS = 11;

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
            // Convert string to int
            std::istringstream iss{argv[++i]};
            iss >> startLevel;
        }
    }
    // Set seed
    srand(seed);

    // Set up players and controller
    Board board1{BOARD_ROWS, BOARD_COLS, new Blank()};
    Board board2{BOARD_ROWS, BOARD_COLS, new Blank()};
    std::string name;
    std::cout << "Enter Player 1 name: ";
    std::getline(std::cin, name);
    Player p1{name, &board1, scriptFile1, startLevel};
    std::cout << "Enter Player 2 name: ";
    std::getline(std::cin, name);
    Player p2{name, &board2, scriptFile2, startLevel};
    board1.setPlayer(&p1);
    board2.setPlayer(&p2);

    // Set up observers
    TextObserver* to = new TextObserver{&board1, &board2, 11, 15, std::cout};
    GraphicsObserver* go;
    if (!textOnly) {
        go = new GraphicsObserver{&board1, &board2, 11, 15};
    }

    Controller ctrl{&p1, &p2};
    
    // // Main game loop
    while (true) {
        // Startup sequence
        ctrl.generateNextBlock(&p1);
        ctrl.generateCurrBlock(&p1);
        ctrl.generateNextBlock(&p2);
        ctrl.generateCurrBlock(&p2);
        ctrl.render();

        // Current game loop
        while (ctrl.takeCommand()) {}
        
        if (std::cin.eof()) {
            break;
        }
        // Set high scores
        // Restart sequence
        // TODO
    }

    // Delete constructors
    delete to;
    delete go;
}
