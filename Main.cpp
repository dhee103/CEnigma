#include "Rotor.hpp"
#include "Plugboard.hpp"
#include "Reflector.hpp"
#include <sstream>
#include <iostream>
#include <fstream>

// declarations of helper functions
void getRotors(int argc, char **argv, std::vector<Component*>* components);
void getPlugboard(char *stream, std::vector<Component*>* components);
int charToInt(char c);
char intToChar(int i);
char encrypt(std::vector<Component*>* components, char c);
void turnRotors(std::vector<Component*>* components);


// declaration of helper functions for testing purposes
//void printVector(std::vector<int> *vector);

int main(int argc, char **argv)
{
/*  create a vector of pointers to the components
    use the appropriate helper functions & constructors to add the relevant
        constructors to the vector */
    std::vector<Component*> components = std::vector<Component*>();
    getPlugboard(argv[argc - 1], &components);
    getRotors(argc, argv, &components);
    Reflector* reflector = new Reflector();
    components.push_back(reflector);

    char c;
    while (std::cin >> c)
    {
        if (isupper(c))
        {
            std::cout << encrypt(&components, c);
            turnRotors(&components);
        }
        else if (!isspace(c))
            throw std::invalid_argument("Received a non upper case character");
    }

//    free(reflector);
    for (Component* component: components) free(component);

    for (int i = 0; i < argc; i++) free(argv[argc]);

    return 0;
}

//void getRotors(int argc, char **argv, std::vector<Component*>* components)
//{
//    for (int i = 1; i < argc - 1; i++)
//    {
//        std::vector<int> *config = new std::vector<int>;
//        std::ifstream rotarfile(argv[i]);
//        if (rotarfile) {
//            int value;
//            while (rotarfile >> value) config->push_back(value);
//            components->push_back(new Rotor(config));
//            rotarfile.close();
//        }
//        else throw std::invalid_argument("not a rotor file");
//    }
//}


void getRotors(int argc, char **argv, std::vector<Component*>* components)
{
    for (int i = 1; i < argc - 1; i++)
    {
        std::ifstream rotorFile(argv[i]);
        if (rotorFile) {
            std::stringstream buffer;
            buffer << rotorFile.rdbuf();
            components->push_back(new Rotor(buffer.str()));
            rotorFile.close();
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
        delete(config);
    }
    else throw std::invalid_argument("not a plugboard file");
}

// remove this code repetition ^


//int charToInt(char c) { return (int)c - '0'; }

int charToInt(char c) {
    if (c >= 'A' || c <= 'Z') {
        return c - 'A';
    }

    std::runtime_error("Only allowed to enter capital A-Z.");
    exit(1);
}

char intToChar(int i) { return (char)('A' + i); }

char encrypt(std::vector<Component*>* components, char c)
{
    int charAsNum = charToInt(c);

    for (unsigned int i = 0; i < components->size(); i++)
    {
        charAsNum = components->at(i)->getForwardsCharAsInt(charAsNum);
    }

    for (int i = components->size() - 2; i >= 0; i--)
    {
//        std::cout << "2nd Loop Count is: " <<  i << std::endl;
        charAsNum = components->at(i)->getBackwardsCharAsInt(charAsNum);
    }

//    std::cout << "Loop End" << std::endl;

    return intToChar(charAsNum);
}

void turnRotors(std::vector<Component*>* components) {
    bool needToTurn = true;
    for (unsigned int i = 1; i < components->size() - 1; i++) {
        if (needToTurn) {
            needToTurn = components->at(i)->shouldRotorTurn();
//            cout << components->at(i)->getNumOfTurns();
        } else {
            //if don't need to turn, nothing else needs to turn
            break;
        }
    }
}



// for testing purposes
//void printVector(std::vector<int> *vector)
//{
//    for (unsigned int i = 0; i < vector->size(); i++)
//    {
//        std::cout << "value at " << i << " is: " << vector->at(i) << std::endl;
//    }
//}