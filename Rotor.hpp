#ifndef __ROTOR_H
#define __ROTOR_H

#include "Component.hpp"

class Rotor : public Component {
public:
    ~Rotor();
    Rotor(std::ifstream rotorFile);
    bool shouldRotorTurn();
    int getNumTurns();

private:
    int numTurns;
    void findOffsets();
    std::vector<int>* parseRotorFile(std::ifstream rotorFile);
};

#endif
