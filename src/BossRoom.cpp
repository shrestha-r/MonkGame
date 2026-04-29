#include "BossRoom.h"
#include "Monk.h"
#include <iostream>
#include <cstdlib>

BossRoom::BossRoom() : boss(30, 6) {}
std::string BossRoom::getType() const {
    return "Boss";
}
void BossRoom::enter(Monk& monk) {
    std::cout << "\n🔥 Boss Room! A powerful Goblin appears!\n";

    while (monk.isAlive() && boss.isAlive()) {

        int action;
        std::cout << "\n1. Attack\n2. Guard\nChoose: ";
        std::cin >> action;

        bool success = rand() % 2;

        // Player turn
        if (action == 1) {
            if (success) {
                boss.takeDamage(monk.getAttack());
                std::cout << "You hit the Boss!\n";
            } else {
                std::cout << "Your attack missed!\n";
            }
        } else {
            monk.heal(1);
            std::cout << "You defend.\n";
        }

        // 🧠 SIMPLE BOSS AI
        if (boss.getHealth() <= 8) {
            boss.heal(2);
            std::cout << "Boss is healing!\n";
        }
        else if (monk.getHealth() <= 6) {
            monk.takeDamage(boss.getAttack());
            std::cout << "Boss goes aggressive!\n";
        }
        else {
            if (rand() % 2) {
                monk.takeDamage(boss.getAttack());
                std::cout << "Boss attacks!\n";
            } else {
                boss.heal(1);
                std::cout << "Boss guards.\n";
            }
        }

        std::cout << "Monk HP: " << monk.getHealth()
                  << " | Boss HP: " << boss.getHealth() << "\n";
    }

    if (!monk.isAlive())
        std::cout << "You were defeated by the Boss.\n";
    else
        std::cout << "Boss defeated!\n";
}