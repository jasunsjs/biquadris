#include "textobserver.h"

void TextObserver::update(){
    //get width and height of the board
    int width = subject->getCols();
    int height = subject->getRows();

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