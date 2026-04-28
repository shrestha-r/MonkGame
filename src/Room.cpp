#include "Room.h"

void Room::connect(Room* room) {
    for (auto r : connections) {
        if (r == room) return;
    }
    connections.push_back(room);
}

std::vector<Room*>& Room::getConnections() {
    return connections;
}