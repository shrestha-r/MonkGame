#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <string>

class Monk;

class Room {
protected:
    std::vector<Room*> connections;

public:
    virtual ~Room() {}
    void connect(Room* room);
    std::vector<Room*>& getConnections();
    virtual void enter(Monk& monk) = 0;
    virtual std::string getType() const = 0;
};

#endif