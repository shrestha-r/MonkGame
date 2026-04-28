#include "MonsterRoom.h"
#include "Monk.h"
#include <iostream>
#include <cstdlib>

void MonsterRoom::enter(Monk& monk) {
    std::cout << "Monster Room! A Goblin appears!\n";

    while (monk.isAlive() && goblin.isAlive()) {
        int playerAction = rand() % 2;
        int goblinAction = rand() % 2;

        if (playerAction == 0 && rand()%2) {
            goblin.takeDamage(monk.getAttack());
            std::cout << "Monk attacks!\n";
        } else if (playerAction == 1 && rand()%2) {
            monk.heal(1);
            std::cout << "Monk guards!\n";
        }

        if (goblinAction == 0 && rand()%2) {
            monk.takeDamage(goblin.getAttack());
            std::cout << "Goblin attacks!\n";
        } else if (goblinAction == 1 && rand()%2) {
            goblin.heal(1);
        }

        std::cout << "Monk HP: " << monk.getHealth()
                  << " Goblin HP: " << goblin.getHealth() << "\n";
    }
}
std::string MonsterRoom::getType() const {
    return "Monster";
}