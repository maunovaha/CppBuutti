#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <ostream>

class Person {
public:
    Person(const std::string first_name, const std::string last_name, const int age);

    friend std::ostream& operator <<(std::ostream& os, const Person& other);

    static const int min_age = 1;
    static const int max_age = 130;
private:
    const std::string first_name_;
    const std::string last_name_;
    const int age_;
};

#endif