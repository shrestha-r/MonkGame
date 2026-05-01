#ifndef GUARDACTION_H
#define GUARDACTION_H

#include "Action.h"
#include <iostream>
#include <cstdlib>

class GuardAction : public Action {
public:
    void execute(Character& actor, Character&) override {
        bool success = rand() % 2;
        if (success) {
            actor.heal(1);
            std::cout << actor.getName() << " recovers 1 HP\n";
        } else {
            std::cout << actor.getName() << " failed to guard\n";
        }
    }
};

#endif