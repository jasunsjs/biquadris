#include "textobserver.h"

TextObserver::TextObserver(Board* s, int w, int h, std::ostream& o) 
: Observer(s, w, h), out(o) {}

void TextObserver::update(){

    out << "------------" << std::endl;

    //updates state of each coord 
    for(int r = 0; r < height; r++){
        for(int c = 0; c < width; c++){
            out << subject->getState(r, c);
        }
        out << std::endl;
    }

     out << "------------" << std::endl;
}