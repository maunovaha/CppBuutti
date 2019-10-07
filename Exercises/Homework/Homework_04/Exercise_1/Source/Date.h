#ifndef DATE_H
#define DATE_H

#include <string>

struct Date {
    Date(short day, short month, short year);

    std::string to_string() const;

    short day;
    short month;
    short year;
};

#endif
