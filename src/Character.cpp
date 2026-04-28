#include "Character.h"

Character::Character(std::string name, int hp, int atk)
    : name(name), health(hp), attack(atk) {}

int Character::getHealth() const { return health; }
int Character::getAttack() const { return attack; }

void Character::takeDamage(int dmg) { health -= dmg; }
void Character::heal(int amount) { health += amount; }
bool Character::isAlive() const { return health > 0; }
std::string Character::getName() const { return name; }