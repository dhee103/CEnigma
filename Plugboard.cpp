#include "Plugboard.hpp"
#include <iostream>

Plugboard::Plugboard(char *stream)
{
/*
    as this is the first of the components we need to initialise the
    component fields (forward and reverse) and the plugboard field here
*/
    forward = new std::vector<int>;
    reverse = new std::vector<int>;
    config  = new std::vector<int>;
    for (int i = 0; i < 26; i++) {
        forward->push_back(0);
        reverse->push_back(0);
        config ->push_back(0);
    }

/*
    uses the private helper function to parse the plugboard and store the
    mappings in the vector config
*/
    parsePlugboard(stream);

//  add the plugboard mappings to forward
    for (unsigned int j = 0; j < config->size(); j+=2) {
        int first = config->at(j);
        int second = config->at(j+1);
        forward->at(first) = second - first;
        forward->at(second) = -1 * forward->at(first);
    }

//    add the plugboard mappings to reverse
    for (unsigned int start = 0; start < forward->size(); start++) {
        int end = (start + forward->at(start)) % 26;
        reverse->at(end) = forward->at(start);
    }
}

/*
    helper function which parses the plugboard in order to store the mappings
    in the vector config
*/
void Plugboard::parsePlugboard(char *stream)
{
    std::ifstream plugboardfile(stream);
    if (plugboardfile)
    {
        int value;
        while (plugboardfile >> value) { config->push_back(value); }
        plugboardfile.close();
    }
    else { std::cerr << "not a plugboard file"; exit(1); }
}