#include "InputReader.h"
#include <iostream>
#include <limits>

std::string InputReader::read_str()
{
    std::string value;
    std::getline(std::cin, value);

    return value;
}

bool InputReader::read_int(int& value, const int min, const int max)
{
    const bool success = static_cast<bool>(std::cin >> value) && (value >= min && value <= max);

    reset();

    return success;
}

void InputReader::reset()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
