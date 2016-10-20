#ifndef __REFLECTOR_H
#define __REFLECTOR_H

#include "Component.hpp"

class Reflector : public Component {
public:
    Reflector();
    bool shouldRotorTurn();
    int getNumTurns();
};

#endif
