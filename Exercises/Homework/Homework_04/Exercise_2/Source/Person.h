#ifndef PERSON_H
#define PERSON_H

#include "Date.h"
#include <string>

struct Person {
    Person(std::string name, std::string gender, std::string occupation, const Date& birthdate, 
           const Date& registration_date, bool active_member = false);

    static void debug();
    void introduce_yourself() const;

    std::string name;
    std::string gender;
    std::string occupation;
    Date birthdate;
    Date registration_date;
    bool active_member;
    
    static int id;
};

#endif
