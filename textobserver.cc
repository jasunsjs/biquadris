#include "textobserver.h"
#include "board.h"

TextObserver::TextObserver(Board* s, int w, int h, std::ostream& o) 
: Observer(s, w, h), out(o) {
    s->attach(this);
}

void TextObserver::update(){
    out << "Level: " << subject->getLevel() << std::endl;
    out << "Score: " << subject->getScore() << std::endl;


    out << "-------------" << std::endl;

    //updates state of each coord 
    for(int r = 0; r < height; r++){
        out << '|';
        for(int c = 0; c < width; c++){
            out << subject->getState(r, c);
        }
        out << '|' << std::endl;
    } 

     out << "-------------" << std::endl;
     out << "Next Block: " << std::endl;

    char nextBlock = subject->getNextBlock();
    auto it = blockShapes.find(nextBlock);

    if (it != blockShapes.end()) {
        for (const std::string& line : it->second) {
            out << line << std::endl;
        }
        out << std::endl;
    } else {
        out << "    " << std::endl;
    }

}