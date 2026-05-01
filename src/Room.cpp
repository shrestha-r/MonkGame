#include "Room.h"

void Room::connect(Room* room) {
    for (auto r : connections)
        if (r == room) return;  // already connected, skip
    connections.push_back(room);
}