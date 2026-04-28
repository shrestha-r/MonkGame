#ifndef DUNGEON_H
#define DUNGEON_H

#include "Room.h"
#include <vector>

class Dungeon {
private:
    std::vector<Room*> rooms;

public:
    Dungeon();
    ~Dungeon();
    void generate();
    Room* getStartRoom();
};

#endif