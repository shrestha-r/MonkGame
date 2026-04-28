#ifndef MONSTERROOM_H
#define MONSTERROOM_H

#include "Room.h"
#include "Goblin.h"

class MonsterRoom : public Room {
private:
    Goblin goblin;
public:
    void enter(Monk& monk) override;
    std::string getType() const override;
};

#endif