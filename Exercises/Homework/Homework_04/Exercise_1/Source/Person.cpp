#include "Person.h"
#include <iostream>
#include <iomanip>
#include <utility>

Person::Person(std::string name, std::string gender, std::string occupation, const Date& birthdate, 
               const Date& registration_date, bool active_member)
    : name{std::move(name)}
    , gender{std::move(gender)}
    , occupation{std::move(occupation)}
    , birthdate{birthdate}
    , registration_date{registration_date}
    , active_member{active_member}
{
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
