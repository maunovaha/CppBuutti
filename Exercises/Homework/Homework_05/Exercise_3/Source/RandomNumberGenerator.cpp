#include "RandomNumberGenerator.h"
#include <cstdlib>

int RandomNumberGenerator::number_between(const int min, const int max)
{
    return min + rand() % ((max + 1) - min);
}