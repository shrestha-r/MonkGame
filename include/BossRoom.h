#ifndef BOSSROOM_H
#define BOSSROOM_H

#include "Room.h"
#include "Goblin.h"

class BossRoom : public Room {
private:
    Goblin boss; // reuse Goblin as boss

public:
    BossRoom();
    void enter(Monk& monk) override;
    std::string getType() const override;
};

#endif