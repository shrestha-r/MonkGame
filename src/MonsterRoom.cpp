#include "MonsterRoom.h"
#include "Monk.h"
#include <iostream>
#include "Combat.h"

void MonsterRoom::enter(Monk &monk)
{
    markVisited();
    std::cout << "Monster Room! A Goblin appears!\n";
    Goblin goblin;
    Combat::start(monk, goblin);
}

std::string MonsterRoom::getType() const
{
    return "Monster";
}