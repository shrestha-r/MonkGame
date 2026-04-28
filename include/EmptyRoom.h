#ifndef EMPTYROOM_H
#define EMPTYROOM_H

#include "Room.h"

class EmptyRoom : public Room {
public:
    void enter(Monk& monk) override;
    std::string getType() const override;
};

#endif