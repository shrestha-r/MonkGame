#ifndef COMBAT_H
#define COMBAT_H

#include "Monk.h"
#include "Character.h"

class Combat {
public:
    static void start(Monk& monk, Character& enemy);
};

#endif