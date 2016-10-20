#ifndef __COMPONENT_H
#define __COMPONENT_H

#define ALPHABET_SIZE 26
#include <vector>
#include <fstream>

class Component {
public:
    ~Component();
    int getForwardsCharAsInt(int);
    int getBackwardsCharAsInt(int);
    virtual bool shouldRotorTurn() = 0;
    virtual int getNumTurns() = 0;

protected:
    std::vector<int>* forward;
    std::vector<int>* reverse;
};

#endif