#include "BossRoom.h"
#include "Monk.h"
#include <iostream>
#include <cstdlib>
#include "Combat.h"

BossRoom::BossRoom() : boss(30, 6,30) {}
std::string BossRoom::getType() const {
    return "Boss";
}

void BossRoom::enter(Monk& monk) {
    markVisited();
    std::cout << "Boss Room!\n";

    Goblin boss(30, 6, 30);
    Combat::start(monk, boss);
}