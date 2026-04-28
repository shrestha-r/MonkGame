#include "MonsterRoom.h"
#include "Monk.h"
#include <iostream>
#include <cstdlib>

void MonsterRoom::enter(Monk& monk) {
    std::cout << "Monster Room! A Goblin appears!\n";

    while (monk.isAlive() && goblin.isAlive()) {

        int choice;
        std::cout << "\nChoose action:\n";
        std::cout << "1. Attack\n2. Guard\n";
        std::cin >> choice;

        bool success = rand() % 2; // 50% chance

        if (choice == 1) {
            if (success) {
                goblin.takeDamage(monk.getAttack());
                std::cout << "You hit the goblin!\n";
            } else {
                std::cout << "Attack missed!\n";
            }
        } 
        else if (choice == 2) {
            if (success) {
                monk.heal(1);
                std::cout << "You recover 1 HP.\n";
            } else {
                std::cout << "Guard failed!\n";
            }
        } 
        else {
            std::cout << "Invalid action.\n";
            continue;
        }

        // Goblin turn (still simple AI)
        int gAction = rand() % 2;

        if (gAction == 0 && rand() % 2) {
            monk.takeDamage(goblin.getAttack());
            std::cout << "Goblin attacks!\n";
        } else {
            goblin.heal(1);
            std::cout << "Goblin defends!\n";
        }

        std::cout << "Monk HP: " << monk.getHealth()
                  << " | Goblin HP: " << goblin.getHealth() << "\n";
    }

    if (!monk.isAlive())
        std::cout << "You died in battle.\n";
    else
        std::cout << "Goblin defeated!\n";
}

std::string MonsterRoom::getType() const {
    return "Monster";
}