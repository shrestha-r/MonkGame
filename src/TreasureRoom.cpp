#include "TreasureRoom.h"
#include <iostream>

void TreasureRoom::enter(Monk&) {
    std::cout << "You found the treasure! You win!\n";
}

std::string TreasureRoom::getType() const {
    return "Treasure";
}