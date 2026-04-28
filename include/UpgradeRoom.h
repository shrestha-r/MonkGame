#ifndef UPGRADEROOM_H
#define UPGRADEROOM_H

#include "Room.h"

class UpgradeRoom : public Room {
public:
    void enter(Monk& monk) override;
    std::string getType() const override;
};

#endif