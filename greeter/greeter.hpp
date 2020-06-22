#pragma once
#include <string>
#include "person.hpp"

class Greeter
{
public:
    Greeter();
    Greeter(const std::string & name);
    Greeter(const Person & person);
    ~Greeter();
    std::string meet() const;

private:
    std::string name_ = "";
};
