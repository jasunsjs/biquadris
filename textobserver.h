#ifndef TEXTOBSERVER_H
#define TEXTOBSERVER_H

#include "observer.h"
#include "window.h"
#include <iostream>

class TextObserver : public Observer {
    std::ostream out;
    void update(){
        
    }

};

#endif