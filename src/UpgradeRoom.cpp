#include "UpgradeRoom.h"
#include "Monk.h"
#include <iostream>

void UpgradeRoom::enter(Monk& monk) {
    markVisited();
    int choice;
    std::cout << "Upgrade Room! (1) Health (2) Attack: ";
    std::cin >> choice;

    if (choice == 1) monk.increaseHealth();
    else monk.increaseAttack();
}

std::string UpgradeRoom::getType() const {
    return "Upgrade";
}