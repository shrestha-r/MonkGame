#ifndef ACTION_H
#define ACTION_H

#include "Character.h"

class Action {
public:
    virtual ~Action() {}
    virtual void execute(Character& attacker, Character& defender) = 0;
};

#endif