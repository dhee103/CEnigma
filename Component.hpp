#ifndef CENIGMA_DSG115_COMPONENT_H
#define CENIGMA_DSG115_COMPONENT_H


#include <vector>

class Component {
public:
    ~Component();
    virtual bool shouldRotorTurn() = 0;
    virtual int getNumTurns() = 0;

protected:
    std::vector<int>* forward = nullptr;
    std::vector<int>* reverse = nullptr;
};




#endif //CENIGMA_DSG115_COMPONENT_H
