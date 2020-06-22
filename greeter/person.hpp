#pragma once
#include <string>

class Person
{
    std::string firstName_ = {};
    std::string lastName_ = {};

public:
    Person(const std::string & firstName, const std::string & lastName);
    Person(const Person & other) = delete;
    std::string getName() const;
};
