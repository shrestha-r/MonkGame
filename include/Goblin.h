#ifndef GOBLIN_H
#define GOBLIN_H

#include "Character.h"

class Goblin : public Character
{
public:
    Goblin();
    Goblin(int hp, int atk,int m);
};

#endif