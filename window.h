#ifndef __WINDOW_H__
#define __WINDOW_H__
#include <X11/Xlib.h>
#include <iostream>
#include <string>

class XWindow {
    Display *d;
    Window w;
    int s, width, height;
    GC gc;
    unsigned long colours[5];

  public:
    XWindow(int width=1000, int height=1000);  // Constructor; displays the window.
    ~XWindow();                              // Destructor; destroys the window.

    enum {White=0, Black, Red, Green, Blue}; // Available colours.

    int getWidth() const;
    int getHeight() const;

    // Draws a rectangle
    void fillRectangle(int x, int y, int width, int height, int colour=Black);

    // Draws a string
    void drawString(int x, int y, std::string msg);

};

#endif
