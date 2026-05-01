#ifndef MONK_H
#define MONK_H

#include "Character.h"

class Monk : public Character {
private:
    std::string description;
public:
    Monk(std::string name);
    void increaseHealth();
    void increaseAttack();
    void fullHeal();
    void setDescription(const std::string& desc);
    std::string getDescription() const;
};

#endif