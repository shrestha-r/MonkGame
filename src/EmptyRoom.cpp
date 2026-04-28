#include "EmptyRoom.h"
#include "Monk.h"
#include <iostream>

void EmptyRoom::enter(Monk& monk) {
    std::cout << "Empty Room. You meditate and heal.\n";
    monk.fullHeal();
}

std::string EmptyRoom::getType() const {
    return "Empty";
}