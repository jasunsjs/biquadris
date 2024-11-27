#ifndef OBSERVER_H
#define OBSERVER_H
#include "board.h"

class Observer {
  protected:
    Board* subject;
    int width;
    int height; 
    Observer(Board* subject, int width, int height)
    : subject(subject), width(width), height(height) {}
  public:
    virtual void update() = 0;
    virtual ~Observer() = default;
};

#endif