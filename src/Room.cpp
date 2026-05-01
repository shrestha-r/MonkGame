#include "Room.h"

void Room::connect(Room* room)
{
    for (auto r : connections)
        if (r == room) return;

    connections.push_back(room);

    // reverse link
    bool exists = false;
    for (auto r : room->connections)
        if (r == this) exists = true;

    if (!exists)
        room->connections.push_back(this);
}