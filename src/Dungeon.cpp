#include "Dungeon.h"
#include "RoomFactory.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

~

Dungeon::~Dungeon()
{
    for (auto r : rooms)
        delete r;
}

void Dungeon::generate()
{
    srand(time(0));
    rooms.clear();

    // Base rooms
    rooms.push_back(RoomFactory::createRoom(EMPTY));
    rooms.push_back(RoomFactory::createRoom(MONSTER));
    rooms.push_back(RoomFactory::createRoom(MONSTER));
    rooms.push_back(RoomFactory::createRoom(UPGRADE));
    rooms.push_back(RoomFactory::createRoom(MONSTER));

    // 👑 Boss + Treasure (ONLY ONCE)
    rooms.push_back(RoomFactory::createRoom(BOSS));
    rooms.push_back(RoomFactory::createRoom(TREASURE));

    // Shuffle only safe part (exclude last 2 rooms)
    std::random_shuffle(rooms.begin(), rooms.end() - 2);
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(rooms.begin(), rooms.end() - 2, g);
    // Ensure connectivity
    for (size_t i = 0; i < rooms.size() - 1; i++)
    {
        rooms[i]->connect(rooms[i + 1]);
        rooms[i + 1]->connect(rooms[i]);
    }

    // Safety: treasure not first
    if (rooms[0]->getType() == "Treasure")
    {
        std::swap(rooms[0], rooms[1]);
    }
}

Room *Dungeon::getStartRoom()
{
    return rooms[0]; // safer than random start
}