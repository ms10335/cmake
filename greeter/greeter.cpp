#include "greeter.hpp"
#include <iostream>

Greeter::Greeter()
{
    std::cout << "Hello handsome :)\n";
}

Greeter::Greeter(const std::string & name)
    : name_(name)
{
    std::cout << "Hello " << name_ << "!\n";
}

Greeter::Greeter(const Person & person)
    : name_(person.getName())
{
    std::cout << "Hello " << name_ << "!\n";
}

Greeter::~Greeter()
{
    std::cout << "Goodbye " << name_ << "!\n";
}

std::string Greeter::meet() const
{
    return "It's nice to meet you " + name_ + " :)\n";
}