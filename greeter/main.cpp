#include <iostream>
#include <string>

#include "greeter.hpp"


int main()
{
    std::cout << "Provide your name: ";
    std::string yourName {};
    std::cin >> yourName;
    Greeter greeter(yourName);
    std::cout << greeter.meet();

    return 0;
}