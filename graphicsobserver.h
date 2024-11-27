#ifndef GRAPHICSOBSERVER_H
#define GRAPHICSOBSERVER_H

#include "observer.h"
#include "window.h"

class GraphicsObserver : public Observer {
    XWindow window;
    const int pixelSize = 1;

    public:
        GraphicsObserver(Board* s, int w, int h, XWindow window);
        void update() override;
        ~GraphicsObserver() override = default;
};

#endif