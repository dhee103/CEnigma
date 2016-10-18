#ifndef CENIGMA_DSG115_ROTOR_H
#define CENIGMA_DSG115_ROTOR_H


#include "Component.hpp"

class Rotor : public Component {
public:
    Rotor(std::vector<int>* config);
    bool shouldRotorTurn();
    int getNumTurns();

private:
    int numTurns;

};


#endif //CENIGMA_DSG115_ROTOR_H
