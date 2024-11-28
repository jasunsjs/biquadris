#ifndef GRAPHICSOBSERVER_H
#define GRAPHICSOBSERVER_H

#include "observer.h"
#include "window.h"

class GraphicsObserver : public Observer {
    XWindow window;
    const int pixelSize = 20;
    std::vector<std::vector<char>> previousState; //cache for effiency, might not use

    public:
        GraphicsObserver(Board* b1, Board* b2, int w, int h);
        int mapBlockToColor(char state);
        void update() override;
        ~GraphicsObserver() override = default;
};

#endif