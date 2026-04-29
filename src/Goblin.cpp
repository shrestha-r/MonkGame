#include "Goblin.h"

Goblin::Goblin() : Character("Goblin", 10, 2) {}

Goblin::Goblin(int hp, int atk)
    : Character("Goblin", hp, atk) {}