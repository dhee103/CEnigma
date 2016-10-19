#include "Rotor.hpp"
#include "Plugboard.hpp"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>


void getRotors(int argc, char **argv, std::vector<Component*>* components);

void getPlugboard(char *stream, std::vector<Component*>* components);

void printVector(std::vector<int> *vector);

int main(int argc, char **argv)
{
    std::vector<Component*> components;
    getRotors(argc, argv, &components);
    getPlugboard(argv[argc - 1], &components);

    char c;
    while (!std::cin)
    {
        std::cin >> c;
        if (isupper(c))
        {
//            runMachine()
//            turnRotor()
            std::cout << "\nencrypt(c)";/*        encrypt(c); */
        }
        else if (!isspace(c))
            throw std::invalid_argument("Received a non upper case character");
    }


    for (Component* c: components) free(c);

    for (int i = 0; i < argc; i++) free(argv[argc]);

    return 0;
}

void getRotors(int argc, char **argv, std::vector<Component*>* components)
{
    for (int i = 1; i < argc - 1; i++)
    {
        std::ifstream rotarfile(argv[i]);
        if (rotarfile) {
            std::vector<int> *config = new std::vector<int>;
            int value;
            while (rotarfile >> value) config->push_back(value);
            components->push_back(new Rotor(config));
            rotarfile.close();
        }
        else throw std::invalid_argument("not a rotor file");
    }
}

void getPlugboard(char *stream, std::vector<Component*>* components)
{
    std::ifstream plugboardfile(stream);
    if (plugboardfile) {
        std::vector<int> *config = new std::vector<int>;
        int value;
        while (plugboardfile >> value) config->push_back(value);
        components->push_back(new Plugboard(config));
        plugboardfile.close();
    }
    else throw std::invalid_argument("not a plugboard file");
}

// remove this code repetition


void printVector(std::vector<int> *vector)
{
    for (unsigned int i = 0; i < vector->size(); i++)
    {
        std::cout << "value at " << i << " is: " << vector->at(i) << std::endl;
    }
}