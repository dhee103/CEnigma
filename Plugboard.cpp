#include "Plugboard.hpp"

Plugboard::Plugboard(std::vector<int>* config) {
    forward = new std::vector<int>;
    reverse = new std::vector<int>;
    for (int i = 0; i < 26; i++) {
        forward->push_back(0);
        reverse->push_back(0);
    }

    for (unsigned int j = 0; j < config->size(); j+=2) {
        int first = config->at(j);
        int second = config->at(j+1);
        forward->at(first) = second - first;
        forward->at(second) = -1 * forward->at(first);
    }

    for (unsigned int start = 0; start < forward->size(); start++) {
        int end = (start + forward->at(start)) % 26;
        reverse->at(end) = forward->at(start);
    }
}