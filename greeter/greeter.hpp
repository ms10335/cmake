#pragma once
#include <string>

class Greeter
{
public:
    Greeter();
    Greeter(std::string name);
    ~Greeter();
    std::string meet() const;

private:
    std::string name_ = "";
};
