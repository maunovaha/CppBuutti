#include "Person.h"
#include <iostream>
#include <iomanip>
#include <utility>

int Person::id = 0;

Person::Person(std::string name, std::string gender, std::string occupation, const Date& birthdate, 
               const Date& registration_date, bool active_member)
    : name{std::move(name)}
    , gender{std::move(gender)}
    , occupation{std::move(occupation)}
    , birthdate{birthdate}
    , registration_date{registration_date}
    , active_member{active_member}
{
    ++id;
    std::cout << "Created a person with id: " << id << std::endl;
}

void Person::debug()
{
    static int total_calls = 0;
    ++total_calls;

    std::cout << "The method `Person::debug()` has been called " << total_calls 
              << " time(s)." << std::endl;
}

void Person::introduce_yourself() const
{
    std::cout << std::boolalpha
              << "\n=============================="
              << "\nName: "              << name
              << "\nGender: "            << gender
              << "\nOccupation: "        << occupation
              << "\nBirthdate: "         << birthdate.to_string()
              << "\nRegistration date: " << registration_date.to_string()
              << "\nActive member: "     << active_member
              << "\n=============================="
              << std::noboolalpha << std::endl;
}
