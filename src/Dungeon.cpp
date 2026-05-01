#include "Dungeon.h"
#include "RoomFactory.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include <iostream>
#include <vector>

Dungeon::Dungeon() {}

Dungeon::~Dungeon() {
    for (auto r : rooms)
        delete r;
}

void Dungeon::printMap(Room* current) {
    std::cout << "\n=== DUNGEON MAP ===\n";
    for (size_t i = 0; i < rooms.size(); i++) {
        std::cout << "  [" << i << "] " << rooms[i]->getType();
        if (rooms[i] == current)
            std::cout << "  <-- YOU ARE HERE";
        else if (rooms[i]->isVisited())
            std::cout << "  (visited)";
        std::cout << "\n";
    }
    std::cout << "===================\n";
}

void Dungeon::generate() {
    rooms.clear();

    // ── Stage 1: Create room pool ──────────────────────────
    rooms.push_back(RoomFactory::createRoom(EMPTY));
    rooms.push_back(RoomFactory::createRoom(MONSTER));
    rooms.push_back(RoomFactory::createRoom(MONSTER));
    rooms.push_back(RoomFactory::createRoom(UPGRADE));
    rooms.push_back(RoomFactory::createRoom(MONSTER));

    // Boss + Treasure always last two (never shuffled)
    rooms.push_back(RoomFactory::createRoom(BOSS));
    rooms.push_back(RoomFactory::createRoom(TREASURE));

    // ── Stage 2: Shuffle only first 5 rooms ───────────────
    std::mt19937 g(std::random_device{}());
    std::shuffle(rooms.begin(), rooms.end() - 2, g);

    // ── Stage 3: Ensure start room is never Treasure/Boss ─
    // (shouldn't happen since they're excluded from shuffle
    //  but safety check anyway)
    if (rooms[0]->getType() == "Treasure" ||
        rooms[0]->getType() == "Boss") {
        std::swap(rooms[0], rooms[1]);
    }

    // ── Stage 4: Spanning tree (guarantees all connected) ─
    std::vector<int> visited   = {0};
    std::vector<int> unvisited;
    for (size_t i = 1; i < rooms.size(); i++)
        unvisited.push_back(i);

    while (!unvisited.empty()) {
        // pick random already-connected room
        int a   = visited[rand() % visited.size()];

        // pick random unconnected room
        int idx = rand() % unvisited.size();
        int b   = unvisited[idx];

        rooms[a]->connect(rooms[b]);

        visited.push_back(b);
        unvisited.erase(unvisited.begin() + idx);
    }

    // ── Stage 5: Extra connections (loops, more fun) ──────
    // Only between first 5 rooms — never directly to Boss/Treasure
    for (int i = 0; i < 2; i++) {
        int a = rand() % 5;
        int b = rand() % 5;
        if (a != b)
            rooms[a]->connect(rooms[b]);
    }
}

Room* Dungeon::getStartRoom() {
    return rooms[0];
}

const std::vector<Room*>& Dungeon::getRooms() const { return rooms; }