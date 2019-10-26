#include "InputReader.h"
#include <limits>

void InputReader::reset()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
