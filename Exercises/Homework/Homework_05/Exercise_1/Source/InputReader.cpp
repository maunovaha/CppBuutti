#include "InputReader.h"
#include <iostream>
#include <utility>
#include <limits>

std::string InputReader::read_str()
{
    std::string value;
    std::getline(std::cin, value);

    return std::move(value);
}

int InputReader::read_int()
{
    int value = 0;
    const bool success = read(value);
    
    reset();

    if (!success) {
        std::cerr << "Invalid value! Try again." << std::endl;
        return read_int();
    }

    return value;
}

bool InputReader::read(int& value)
{
    return static_cast<bool>(std::cin >> value);
}

void InputReader::reset()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
