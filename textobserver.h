#ifndef TEXTOBSERVER_H
#define TEXTOBSERVER_H

#include "observer.h"
#include "window.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

class TextObserver : public Observer {
    std::ostream& out;
    const std::unordered_map<char, std::vector<std::string>> blockShapes = {
        {'I', {"IIII"}},          // I-block
        {'J', {"J  ", "JJJ"}},    // J-block
        {'L', {"  L", "LLL"}},    // L-block
        {'O', {"OO", "OO"}},      // O-block
        {'S', {" SS", "SS "}},    // S-block
        {'Z', {"ZZ ", " ZZ"}},    // Z-block
        {'T', {"TTT", " T "}}     // T-block
    };

    public:
        TextObserver(Board* s, int w, int h, std::ostream& o);
        void update() override;
        ~TextObserver() override = default;

};

#endif