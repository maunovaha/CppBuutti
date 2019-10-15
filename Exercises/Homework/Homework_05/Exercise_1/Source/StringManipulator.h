#ifndef STRING_MANIPULATOR_H
#define STRING_MANIPULATOR_H

#include <string>

class StringManipulator {
public:
    static std::string to_caesar_chiper(const std::string& value, const int shift_amount);
};

#endif