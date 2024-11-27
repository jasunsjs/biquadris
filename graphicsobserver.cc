#include "graphicsobserver.h"

GraphicsObserver::GraphicsObserver(Board* s, int w, int h)
: Observer(s, w, h), window(100, 100) {
    s->attach(this);
}

int GraphicsObserver::mapBlockToColor(char state){
        int color;
        //determines color based on the type of block we encounter
        if(state == 'I'){
            color = XWindow::Red;
        } else if (state == 'T') {
            color = XWindow::Green;
        } else if (state == 'Z') {
            color = XWindow::Blue;
        } else if (state == 'O') {
            color = XWindow::Black;
        } else if (state != ' ') {
            color = XWindow::Black;
        } else {
            color = XWindow::White;
        }

        return color;
}

void GraphicsObserver::update(){
    for(int r = 0; r < height; r++){
        for(int c = 0; c < width; c++){
            char state = subject->getState(r, c);
            int color = mapBlockToColor(state);

            //draw the block
            int x = c * pixelSize;
            int y = r * pixelSize;

            window.fillRectangle(x, y, pixelSize, pixelSize, color);
        }
    }


}


