#include "Plugboard.hpp"
#include <sstream>
#include <iterator>

const std::vector<Pair> ALPHABET = {('A','A'), ('B','B'), ('C','C')};

std::vector<Pair> Plugboard::buildPairs(std::string stream)
{
    std::vector<Pair> mapping;

}

std::vector<int> Plugboard::parseInts(const std::string& stream)
{
    std::istringstream is(stream);
    std::vector<int> ints = std::vector<int>(std::istream_iterator<int>(is),
                                           std::istream_iterator<int>());
    std::vector<Pair> mapping;
    for (int i = 0; i < ints.size() - 1; i++)
    {
        mapping[i] = new Pair(ints[i], ints[i+1]);
    }
}

