#include "Goblin.h"

Goblin::Goblin() : Character("Goblin", 10, 2,10) {}

Goblin::Goblin(int hp, int atk,int m)
    : Character("Goblin", hp, atk, m) {} // for boss