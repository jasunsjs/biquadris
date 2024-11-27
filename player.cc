#include "player.h"

Player::Player(const std::string& name, Board* b, const std::string& filename)
    : playerName{name},
      level{0},
      score{0}
      inputFilename{filename} {}

void Player::applyEffect() {
    // TODO
}

void Player::setLevel(int lvl) {
    level = lvl;
}

std::string Player::getName() {
    return playerName;
}

int Player::getLevel() {
    return level;
}

int Player::getScore() {
    return score;
}

