#ifndef MONK_H
#define MONK_H

#include "Character.h"

class Monk : public Character {
private:
    int maxHealth;

public:
    Monk(std::string name);
    void increaseHealth();
    void increaseAttack();
    void fullHeal();
};

#endif