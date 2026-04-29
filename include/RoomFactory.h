#ifndef ROOMFACTORY_H
#define ROOMFACTORY_H

#include "Room.h"

enum RoomType { EMPTY, MONSTER, UPGRADE, BOSS, TREASURE };

class RoomFactory {
public:
    static Room* createRoom(RoomType type);
};

#endif