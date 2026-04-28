#include "RoomFactory.h"
#include "EmptyRoom.h"
#include "MonsterRoom.h"
#include "UpgradeRoom.h"
#include "TreasureRoom.h"

Room* RoomFactory::createRoom(RoomType type) {
    switch (type) {
        case EMPTY: return new EmptyRoom();
        case MONSTER: return new MonsterRoom();
        case UPGRADE: return new UpgradeRoom();
        case TREASURE: return new TreasureRoom();
    }
    return nullptr;
}