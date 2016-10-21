#include "Rotor.hpp"
#include "Plugboard.hpp"
#include "Reflector.hpp"
#include <sstream>
#include <iostream>

// declarations of main program functions
char encrypt(std::vector<Component*>* components, char c);
void turnRotors(std::vector<Component*>* components);

// declarations of helper functions
int charToInt(char c);
char intToChar(int i);

int main(int argc, char **argv)
{
//  check if there are any arguments and if so exit with an error
    if (argc <= 1) { std::cerr << "not enough arguments passed"; exit(1); }

/*
    create a vector of pointers to the components
    use the appropriate helper functions & constructors to add the relevant
    constructors to the vector in the order that the input will travel
    i.e. plugboard then rotors then reflector
*/
    std::vector<Component*> components = std::vector<Component*>();
    components.push_back(new Plugboard(argv[argc - 1]));
    for (int i = 1; i < argc - 1; i++) {
        components.push_back(new Rotor(argv[i]));
    }
    components.push_back(new Reflector());

/*
    main program loop
    Reads in  character as long as there as one from std:cin. If there isn't
    this means that the user input has finished so the program ends
    appropriately. After reading in the character it checks if it's valid. If
    it's upper case then it will perform the encryption. If it's not then it
    checks if it's a space character, if it is then the character is ignored
    but if it's not a space character then we know it must invalid so an
    error message is output
 */
    char c;
    while (std::cin >> c)
    {
        if (isupper(c))
        {
            std::cout << encrypt(&components, c);
            turnRotors(&components);
        }
        else if (!isspace(c)) { std::cerr << "not a valid character"; exit(1); }
    }

//    free components and program arguments
    for (Component* component: components) free(component);
    for (int i = 0; i < argc; i++) free(argv[argc]);

    return 0;
}

/*
    For encrypt, the input and output is a char but I work with integers
    within my program so I use two helper functions to convert to and from
    integers.
    Encrypt goes through my components vector and getting the result of that
    component on the character i.e. through the loop, charAsNum will hold the
    value of the character after the plugboard, the rotors and finally the
    reflector.
    This is done both forwards (the 1st for loop) and in reverse (the 2nd for
    loop).
*/

char encrypt(std::vector<Component*>* components, char c)
{
    int charAsNum = charToInt(c);

    for (unsigned int i = 0; i < components->size(); i++)
    {
        charAsNum = components->at(i)->getForwardsCharAsInt(charAsNum);
    }

    for (int i = components->size() - 2; i >= 0; i--)
    {
        charAsNum = components->at(i)->getBackwardsCharAsInt(charAsNum);
    }

    return intToChar(charAsNum);
}


/*
    Runs shouldNextRotorTurn() from components for each rotor
    This will turn the current rotor and then check if the next rotor should
    be turned next time and sets it accordingly
*/
void turnRotors(std::vector<Component*>* components)
{
    bool shouldNextRotorTurn = true;
    for (unsigned int i = 1; i < components->size() - 1; i++)
    {
        if (shouldNextRotorTurn)
            { shouldNextRotorTurn = components->at(i)->shouldNextRotorTurn(); }
        else { break; }
    }
}

int charToInt(char c)
{
    if (c >= 'A' || c <= 'Z') { return c - 'A'; }
    std::cerr << "conversion from char to int failed"; exit(1);
}

char intToChar(int i)
{
    if (i >= 0 && i <= 26) { return (char)('A' + i); }
    std::cerr << "conversion from int to char failed"; exit(1);
}