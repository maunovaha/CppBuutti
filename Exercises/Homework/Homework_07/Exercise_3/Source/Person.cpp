#include "Person.h"
#include <iostream>
#include <utility>

Person::Person(const std::string first_name, const std::string last_name, const int age)
    : first_name_{std::move(first_name)}
    , last_name_{std::move(last_name)}
    , age_{age}
{
    std::cout << *this;
}

std::ostream& operator <<(std::ostream& os, const Person& other)
{
    os << "--- " << other.first_name_ << " " << other.last_name_ << ", " << other.age_ 
       << " ---" << std::endl;

    return os;
}
