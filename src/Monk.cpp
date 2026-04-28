#include "Monk.h"

Monk::Monk(std::string name) : Character(name, 15, 3), maxHealth(15) {}

void Monk::increaseHealth() {
    maxHealth += 5;
    health = maxHealth;
}

void Monk::increaseAttack() {
    attack += 2;
}

void Monk::fullHeal() {
    health = maxHealth;
}