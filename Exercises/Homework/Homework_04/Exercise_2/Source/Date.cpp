#include "Date.h"

Date::Date(short day, short month, short year) : day{day}, month{month}, year{year}
{
}

std::string Date::to_string() const
{
    return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
}
