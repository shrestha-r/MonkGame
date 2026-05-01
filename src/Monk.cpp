#include "Monk.h"

Monk::Monk(std::string name) : Character(name, 15, 3,15) {}

void Monk::increaseHealth() {
    maxHealth += 5;
    health = maxHealth; // optional: full restore
}
void Monk::increaseAttack() {
    attack += 2;
}

void Monk::fullHeal() {
    health = maxHealth;
}

void Monk::setDescription(const std::string& desc) {
    description = desc;
}

std::string Monk::getDescription() const {
    return description;
}