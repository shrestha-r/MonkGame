#include "Character.h"

Character::Character(std::string name, int hp, int atk,int maxHP)
    : name(name), health(hp), attack(atk),maxHealth(maxHP) {}

int Character::getHealth() const { return health; }
int Character::getAttack() const { return attack; }

void Character::takeDamage(int dmg) { health -= dmg; }
void Character::heal(int amount) {
    health += amount;
    if (health > maxHealth) health = maxHealth; 
}
bool Character::isAlive() const { return health > 0; }
std::string Character::getName() const { return name; }