#include "player.h"
#include "board.h"
#include "controller.h"
#include "observer.h"
#include "decorator.h"
#include <string>
#include <iostream>

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
    // Set up players and controller
    Player p1;
    Player p2;
    std::string name;
    std::cout << "Enter Player 1 name: ";
    std::getline(std::cin, name)
    p1.setName(name);
    std::cout << "Enter Player 2 name: ";
    std::getline(std::cin, name)
    p2.setName(name);
    p1.setInputFile(scriptFile1);
    p2.setInputFile(scriptFile2);
    Board board1{11, 15, new Blank()};
    Board board2{11, 15, new Blank()};
    p1.setBoard(&board1);
    p2.setBoard(&board2);
    // Set up observers
    if (textOnly) {
        board1.attach(new TextObserver(&board1));
        board2.attach(new TextObserver(&board2));
    } else {
        board1.attach(new TextObserver(&board1));
        board2.attach(new TextObserver(&board2));
        board1.attach(new GraphicsObserver(&board1));
        board2.attach(new GraphicsObserver(&board2));
    }
    Controller ctrl{&p1, &p2};
    // Main game loop
    // TODO
}
