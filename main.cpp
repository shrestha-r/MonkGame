#include "Dungeon.h"
#include "Monk.h"
#include <iostream>
#include <limits>
#include <random>
#include <ctime>

int main()
{
    std::string name, description;
    
    std::cout << "Enter Monk name: ";
    std::cin >> name;
    
    std::cin.ignore(); // important
    std::cout << "Enter Monk description: ";
    std::getline(std::cin, description);
    
    srand(time(0));
    
    Monk monk(name);
    monk.setDescription(description);

    Dungeon dungeon;
    dungeon.generate();
    
    Room *current = dungeon.getStartRoom();
    std::cout << "\nConnected rooms:\n";

    auto &conns = current->getConnections();

    for (size_t i = 0; i < conns.size(); i++)
    {
        std::cout << i << ". " << conns[i]->getType();

        if (conns[i]->isVisited())
            std::cout << " (visited)";

        std::cout << "\n";
    }

    while (monk.isAlive())
    {
        std::cout << "\nYou are in a " << current->getType() << " room\n";
        current->enter(monk);

        if (!monk.isAlive())
            break;
        if (current->getType() == "Treasure")
            break;

        std::cout << "\nConnected rooms:\n";

        auto &conns = current->getConnections();
        for (size_t i = 0; i < conns.size(); i++)
        {
            std::cout << i << ". " << conns[i]->getType();
            if (conns[i]->isVisited())
                std::cout << " (visited)";
            std::cout << "\n";
        }

        int choice;
        std::cin >> choice;
        // safe inputs
        while (choice < 0 || choice >= conns.size())
        {
            std::cout << "Invalid choice. Try again: ";
            std::cin >> choice;
        }

        current = conns[choice];
    }
    if (!monk.isAlive())
        std::cout << "You died. Game Over.\n";

    return 0;
}