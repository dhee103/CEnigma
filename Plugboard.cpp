#include "Plugboard.hpp"

Plugboard::Plugboard(std::vector<int>* config) {
    forward = new std::vector<int>;
    for (int i = 0; i < 26; i++) {
        //fill everything with 0 to start off with
        forward->push_back(0);
    }

    for (unsigned int j = 0; j < config->size(); j+=2) {
        int first = config->at(j);
        int second = config->at(j+1);
        forward->at(first) = second - first;
        forward->at(second) = -1 * forward->at(first);
    }

    reverse = new std::vector<int>;
    for (int i = 0; i < 26; i++) {
        //fill everything with 0 to start off with
        reverse->push_back(0);
    }

    for (unsigned int start = 0; start < forward->size(); start++) {
        int end = (start + forward->at(start)) % 26;
        reverse->at(end) = forward->at(start);
    }
}




