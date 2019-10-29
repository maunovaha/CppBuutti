#include "InputReader.h"
#include <iostream>

std::string InputReader::read()
{
    std::string input;
    std::getline(std::cin, input);

    return input;
}