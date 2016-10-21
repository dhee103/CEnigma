#ifndef __ROTOR_H
#define __ROTOR_H

#include "Component.hpp"

class Rotor : public Component {
public:
//    Rotor(std::vector<int>* config);
    Rotor(char *arg);
    bool shouldRotorTurn();
    int getNumTurns();

private:
    int numTurns;
    void findOffsets();
    void parseRotor(char *arg);
};

#endif
