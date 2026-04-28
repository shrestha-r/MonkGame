#include "Dungeon.h"
#include "Monk.h"
#include <iostream>
#include <limits>

int main() {
    std::string name;
    std::cout << "Enter Monk name: ";
    std::cin >> name;

    Monk monk(name);
    Dungeon dungeon;
    dungeon.generate();

    Room* current = dungeon.getStartRoom();
    while (monk.isAlive()) {
    std::cout << "\nYou are in a " << current->getType() << " room\n";
    current->enter(monk);

    if (!monk.isAlive()) break;
    if (current->getType() == "Treasure") break;

    auto& conns = current->getConnections();

    // 🔹 Print options clearly
    std::cout << "\nConnected rooms:\n";
    for (size_t i = 0; i < conns.size(); ++i) {
        std::cout << i << ": " << conns[i]->getType() << " room\n";
    }

    int choice;

    // 🔒 Safe input loop
    while (true) {
        std::cout << "Choose next room (0-" << conns.size() - 1 << "): ";
        std::cin >> choice;

        // Handle non-number input
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a number.\n";
            continue;
        }

        // Handle out-of-range input
        if (choice < 0 || choice >= (int)conns.size()) {
            std::cout << "Invalid choice. Try again.\n";
            continue;
        }

        break; // valid input
    }

    current = conns[choice];
}
    if (!monk.isAlive())
        std::cout << "You died. Game Over.\n";

    return 0;
}