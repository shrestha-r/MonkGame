#ifndef TREASUREROOM_H
#define TREASUREROOM_H

#include "Room.h"

class TreasureRoom : public Room {
public:
    void enter(Monk& monk) override;
    std::string getType() const override;
};

#endif