#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <string>

class Monk;

class Room {
protected:
    bool visited;
    std::vector<Room*> connections;

public:
    Room(): visited(false){}
    virtual ~Room() {}
    void connect(Room* room);
    
    const std::vector<Room*>& getConnections() const{ return connections;}

    virtual void enter(Monk& monk) = 0;
    virtual std::string getType() const = 0;

    bool isVisited() const {return visited;}
    void markVisited() { visited = true; }

};

#endif