#include "Dungeon.h"
#include "RoomFactory.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

Dungeon::Dungeon() {}

Dungeon::~Dungeon() {
    for (auto r : rooms) delete r;
}

void Dungeon::generate() {
    srand(time(0));

    int totalRooms = 5 + rand() % 3; // 5–7 rooms

    // Ensure required rooms exist
    rooms.push_back(RoomFactory::createRoom(TREASURE));
    rooms.push_back(RoomFactory::createRoom(UPGRADE));
    rooms.push_back(RoomFactory::createRoom(MONSTER));
    rooms.push_back(RoomFactory::createRoom(MONSTER));
    rooms.push_back(RoomFactory::createRoom(EMPTY));

    // Fill remaining randomly
    for (int i = 5; i < totalRooms; i++) {
        int type = rand() % 3; // no extra treasure
        rooms.push_back(RoomFactory::createRoom(static_cast<RoomType>(type)));
    }

    // Shuffle rooms
    std::random_shuffle(rooms.begin(), rooms.end());

    // Ensure connectivity (spanning tree)
    for (int i = 0; i < totalRooms - 1; i++) {
        rooms[i]->connect(rooms[i + 1]);
        rooms[i + 1]->connect(rooms[i]);
    }

    // Add extra random connections
    for (int i = 0; i < totalRooms; i++) {
        int extraConnections = rand() % 2; // 0 or 1 extra
        for (int j = 0; j < extraConnections; j++) {
            int target = rand() % totalRooms;
            if (target != i) {
                rooms[i]->connect(rooms[target]);
                rooms[target]->connect(rooms[i]);
            }
        }
    }
}

Room* Dungeon::getStartRoom() {
    return rooms[rand() % rooms.size()];
}