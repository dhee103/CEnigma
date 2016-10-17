#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{

//    plugboard = argv[argc];
//    vector<rotors> rot;
//    for (int i = 1; i < argc; i++)
//    {
//        rot = argv[i];
//    }

    char c;
    cout << "enter: ";
    while (cin.get(c))
    {
        cin >> c;
        if (isupper(c)) { cout << "\nencrypt(c)";/*        encrypt(c); */}
        else if (!isspace(c))
            throw std::invalid_argument("Recieved a non upper case character");

    }

    return 0;
}
