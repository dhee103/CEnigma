//
// Created by dsg115 on 17/10/16.
//

#ifndef CENIGMA_DSG115_PLUGBOARD_H
#define CENIGMA_DSG115_PLUGBOARD_H

#include "Pair.hpp"
#include "Component.hpp"
#include <vector>
#include <string>

class Plugboard : public Component{
private:
    void firstConfig(std::vector<int>*);
public:
    Plugboard(std::vector<int>*);

};


#endif //CENIGMA_DSG115_PLUGBOARD_H
