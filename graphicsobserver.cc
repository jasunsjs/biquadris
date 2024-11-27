#include "graphicsobserver.h"

GraphicsObserver::GraphicsObserver(Board* s, int w, int h, XWindow window)
: Observer(s, w, h), window(window) {}

void GraphicsObserver::update(){

    for(int r = 0; r < height; r++){
        for(int c = 0; c < width; c++){
            char cellState = subject->getState(r, c);
            int color;


            //determines color based on the type of block we encounter
            if(cellState == 'I'){
                color = XWindow::Red;
            } else if (cellState == 'T') {
                color = XWindow::Green;
            } else if (cellState == 'Z') {
                color = XWindow::Blue;
            } else if (cellState == 'O') {
                color = XWindow::Black;
            } else if (cellState != ' ') {
                color = XWindow::Black;
            } else {
                color = XWindow::White;
            }

            //draw the block

        }
    }

}


