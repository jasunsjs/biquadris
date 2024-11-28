#include "graphicsobserver.h"

GraphicsObserver::GraphicsObserver(Board* b1, Board* b2, int w, int h)
: Observer(b1, b2, w, h), window(800, 500), board1Cache(h, std::vector<char>(w, ' ')), 
 board2Cache(h, std::vector<char>(w, ' ')) {
    s1->attach(this);
    s2->attach(this);
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
            color = XWindow::Yellow;
        } else if (state == 'L') {
            color = XWindow::Magenta;
        }
        else if (state != ' ') {
            color = XWindow::Black;
        } else {
            color = XWindow::White;
        }

        return color;
}

void GraphicsObserver::update() {

    int board1OffsetX = 4 * pixelSize;
    int board2OffsetX = 20 * pixelSize;
    int uiHeight = 100;

    window.drawString(board1OffsetX + 10, 20, "Player 1: " + s1->getPlayerName());
    window.drawString(board1OffsetX + 10, 40, "Level: " + std::to_string(s1->getLevel()));
    window.drawString(board1OffsetX + 10, 60, "Score: " + std::to_string(s1->getScore()));

    window.drawString(board2OffsetX + 10, 20, "Player 2: "+ s2->getPlayerName());
    window.drawString(board2OffsetX + 10, 40, "Level: " + std::to_string(s2->getLevel()));
    window.drawString(board2OffsetX + 10, 60, "Score: " + std::to_string(s2->getScore()));

    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            char state1 = s1->getState(c, r);

            if (state1 != board1Cache[c][r]) { 
                int color1 = mapBlockToColor(state1);
                int x1 = board1OffsetX + r * pixelSize;
                int y1 = uiHeight + c * pixelSize;
                window.fillRectangle(x1, y1, pixelSize, pixelSize, color1);
                board1Cache[c][r] = state1;
            }

            char state2 = s2->getState(c, r);

            if (state2 != board2Cache[c][r]) { 
                int color2 = mapBlockToColor(state2);
                int x2 = board1OffsetX+ board2OffsetX + r * pixelSize;
                int y2 = uiHeight + c * pixelSize;
                window.fillRectangle(x2, y2, pixelSize, pixelSize, color2);
                board2Cache[c][r] = state2;
            }
        }
    }

    int nextBlockOffsetY = uiHeight + height * pixelSize + 20;

    window.drawString(board1OffsetX + 10, nextBlockOffsetY, "Next Block:");
    char nextBlock1 = s1->getNextBlock();
    auto it1 = blockShapes.find(nextBlock1);
    if (it1 != blockShapes.end()) {
        const std::vector<std::string>& shape = it1->second;
        for (int i = 0; i < shape.size(); i++) {
            for (int j = 0; j < shape[i].size(); j++) {
                char cell = shape[i][j];   
                int x = board1OffsetX + 10 + j * pixelSize;
                int y = nextBlockOffsetY + 20 + i * pixelSize;
                int blockColor = mapBlockToColor(cell);
                window.fillRectangle(x, y, pixelSize, pixelSize, blockColor);   
            }
        }
    }

    window.drawString(board1OffsetX + board2OffsetX + 10, nextBlockOffsetY, "Next Block:");
    char nextBlock2 = s2->getNextBlock();
    auto it2 = blockShapes.find(nextBlock2);
    if (it2 != blockShapes.end()) {
        const std::vector<std::string>& shape = it2->second;
        for (int i = 0; i < shape.size(); i++) {
            for (int j = 0; j < shape[i].size(); j++) {
                char cell = shape[i][j];
                int x = board1OffsetX + board2OffsetX + 10 + j * pixelSize;
                int y = nextBlockOffsetY + 20 + i * pixelSize;
                int blockColor = mapBlockToColor(cell);
                window.fillRectangle(x, y, pixelSize, pixelSize, blockColor);
            }
        }
    }
}
