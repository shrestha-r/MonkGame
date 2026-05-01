#ifndef ATTACKACTION_H
#define ATTACKACTION_H

#include "Action.h"
#include <iostream>
#include <cstdlib>

class AttackAction : public Action {
public:
    void execute(Character& attacker, Character& defender) override {
        bool success = rand() % 2;
        if (success) {
            defender.takeDamage(attacker.getAttack());
            std::cout << attacker.getName() << " hits!\n";
        } else {
            std::cout << attacker.getName() << " missed!\n";
        }
    }
};

#endif