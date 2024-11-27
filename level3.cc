#include "level3.h"
#include <cstdlib>

Level3::Level3() : Level{3} {
    blockWeights = {
        {'I', 1},
        {'J', 1},
        {'L', 1},
        {'O', 1},
        {'S', 2},
        {'Z', 2},
        {'T', 1}
    };
    totalWeight = 9;
}

char Level3::nextBlock() {
    // Generate a random number from 0 to totalWeight - 1
    int random = rand() % totalWeight;
    // Increment sum by weights to select block according to random number
    int currSum = 0;
    for (const auto& entry : blockWeights) {
        currSum += entry.second;
        if (random < currSum) {
            return entry.first;
        }
    }
    // Invalid weights, return default
    return 'I';
}
