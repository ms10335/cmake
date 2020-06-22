#include "person.hpp"

Person::Person(const std::string & firstName, const std::string & lastName)
    : firstName_(firstName)
    , lastName_(lastName)
{}

std::string Person::getName() const
{
    return firstName_;
}
