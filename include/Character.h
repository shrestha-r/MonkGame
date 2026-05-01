#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
protected:
    std::string name;
    int health;
    int attack;
    int maxHealth;

public:
    Character(std::string name, int hp, int atk,int m);
    virtual ~Character() {}

    int getHealth() const;
    int getAttack() const;
    void takeDamage(int dmg);
    void heal(int amount);
    bool isAlive() const;
    std::string getName() const;
};

#endif