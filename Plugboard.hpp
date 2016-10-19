#ifndef CENIGMA_DSG115_PLUGBOARD_H
#define CENIGMA_DSG115_PLUGBOARD_H

#include "Component.hpp"
#include <vector>
#include <string>

class Plugboard : public Component{
public:
    Plugboard(std::vector<int>*);
    bool shouldRotorTurn() { return false; }
    int getNumTurns() { return -1; }
};


#endif //CENIGMA_DSG115_PLUGBOARD_H
