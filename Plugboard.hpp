//
// Created by dsg115 on 17/10/16.
//

#ifndef CENIGMA_DSG115_PLUGBOARD_H
#define CENIGMA_DSG115_PLUGBOARD_H

#include "Pair.hpp"
#include <vector>
#include <string>

class Plugboard {
private:
    std::string stream;
public:
    std::vector<Pair> buildPairs(std::string stream);
    std::vector<int> parseInts(const std::string& stream);
};


#endif //CENIGMA_DSG115_PLUGBOARD_H
