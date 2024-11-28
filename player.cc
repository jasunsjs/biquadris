#include "player.h"

Player::Player(const std::string& name, Board* b, const std::string& filename, int startLevel)
    : playerName{name},
      score{0},
      currEffect{nullptr},
      inputFilename{filename},
      board{b} {
    setLevel(startLevel);
}

void Player::applyEffect() {
    if (!currEffect) {
        return;
    }
    currEffect->apply(board);
}

void Player::setLevel(int levelNum) {
    switch (levelNum) {
        case 0:
            delete level;
            level = new Level0{inputFilename};
            break;
        case 1:
            delete level;
            level = new Level1{inputFilename};
            break;
        case 2:
            delete level;
            level = new Level2{inputFilename};
            break;
        case 3:
            delete level;
            level = new Level3{inputFilename};
            break;
        case 4:
            delete level;
            level = new Level4{inputFilename};
            break;
    }
}

std::string Player::getName() {
    return playerName;
}

Level* Player::getLevel() {
    return level;
}

int Player::getScore() {
    return score;
}

Board* Player::getBoard() {
    return board;
}
