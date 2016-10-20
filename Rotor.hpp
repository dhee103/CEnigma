#ifndef __ROTOR_H
#define __ROTOR_H

#include "Component.hpp"

class Rotor : public Component {
public:
    ~Rotor();
    Rotor(std::string rotorStream);
    bool shouldRotorTurn();
    int getNumTurns();

private:
    int numTurns;
    void findOffsets();
    void parseRotorFile(std::string rotorFile);
};

#endif
