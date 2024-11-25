#ifndef BOARD_H
#define BOARD_H
#include "decorator.h"

class Board {
    private:
        int width, height;
        Decorator* picture;
    
    public:
        char getState(int x, int y);
        void removeLayer();
        void checkBoard();
        
};

#endif