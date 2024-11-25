#ifndef GRAPHICSOBSERVER_H
#define GRAPHICSOBSERVER_H

#include "observer.h"
#include "window.h"

class GraphicsObserver : public Observer {
    XWindow window;
    const int pixelSize;

    void update(){
        
    }


};

#endif