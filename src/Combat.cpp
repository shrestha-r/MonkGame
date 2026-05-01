#include "Combat.h"
#include "AttackAction.h"
#include "GuardAction.h"
#include <iostream>

void Combat::start(Monk& monk, Character& enemy) {
    AttackAction attack;
    GuardAction guard;

    while (monk.isAlive() && enemy.isAlive()) {
        int choice;

        std::cout << "\n1. Attack\n2. Guard\nChoose: ";
        std::cin >> choice;

        if (choice == 1)
            attack.execute(monk, enemy);
        else if (choice == 2)
            guard.execute(monk, enemy);
        else {
            std::cout << "Invalid input\n";
            continue;
        }

        // Enemy turn (simple AI)
        if (rand() % 2)
            attack.execute(enemy, monk);
        else
            guard.execute(enemy, monk);

        std::cout << "Monk HP: " << monk.getHealth()
                  << " | Enemy HP: " << enemy.getHealth() << "\n";
    }

    if (!monk.isAlive())
        std::cout << "You died.\n";
    else
        std::cout << "Enemy defeated!\n";
}