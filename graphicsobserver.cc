#include "graphicsobserver.h"

GraphicsObserver::GraphicsObserver(Board* b1, Board* b2, int w, int h)
: Observer(b1, b2, w, h), window(800, 500) {
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
            color = XWindow::Green;
        } else if (state == 'L') {
            color = XWindow::Blue;
        }
        else if (state != ' ') {
            color = XWindow::Black;
        } else {
            color = XWindow::White;
        }

        return color;
}

void GraphicsObserver::update() {
    int board2OffsetX = 20 * pixelSize;
    int uiHeight = 100;

    window.drawString(10, 20, "Player 1");
    window.drawString(10, 40, "Level: " + std::to_string(s1->getPlayer()->getLevel()->getLevelNum()));
    window.drawString(10, 60, "Score: " + std::to_string(s1->getPlayer()->getScore()));

    window.drawString(board2OffsetX + 10, 20, "Player 2");
    window.drawString(board2OffsetX + 10, 40, "Level: " + std::to_string(s2->getPlayer()->getLevel()->getLevelNum()));
    window.drawString(board2OffsetX + 10, 60, "Score: " + std::to_string(s2->getPlayer()->getScore()));

    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            char state1 = s1->getState(r, c);
            int color1 = mapBlockToColor(state1);
            int x1 = c * pixelSize;
            int y1 = uiHeight + r * pixelSize;
            window.fillRectangle(x1, y1, pixelSize, pixelSize, color1);

            char state2 = s2->getState(r, c);
            int color2 = mapBlockToColor(state2);
            int x2 = board2OffsetX + c * pixelSize;
            int y2 = uiHeight + r * pixelSize;
            window.fillRectangle(x2, y2, pixelSize, pixelSize, color2);
        }
    }

    int nextBlockOffsetY = uiHeight + height * pixelSize + 20;

    window.drawString(10, nextBlockOffsetY, "Next Block:");
    char nextBlock1 = s1->getNextBlock();
    auto it1 = blockShapes.find(nextBlock1);
    if (it1 != blockShapes.end()) {
        const std::vector<std::string>& shape = it1->second;
        for (size_t i = 0; i < shape.size(); i++) {
            for (size_t j = 0; j < shape[i].size(); j++) {
                char cell = shape[i][j];
                if (cell != ' ') {
                    int x = 10 + j * pixelSize;
                    int y = nextBlockOffsetY + 20 + i * pixelSize;
                    int color = mapBlockToColor(cell);
                    window.fillRectangle(x, y, pixelSize, pixelSize, color);
                }
            }
        }
    }

    window.drawString(board2OffsetX + 10, nextBlockOffsetY, "Next Block:");
    char nextBlock2 = s2->getNextBlock();
    auto it2 = blockShapes.find(nextBlock2);
    if (it2 != blockShapes.end()) {
        const std::vector<std::string>& shape = it2->second;
        for (size_t i = 0; i < shape.size(); i++) {
            for (size_t j = 0; j < shape[i].size(); j++) {
                char cell = shape[i][j];
                if (cell != ' ') {
                    int x = board2OffsetX + 10 + j * pixelSize;
                    int y = nextBlockOffsetY + 20 + i * pixelSize;
                    int color = mapBlockToColor(cell);
                    window.fillRectangle(x, y, pixelSize, pixelSize, color);
                }
            }
        }
    }
}
