#include "Lottery.h"
#include "RandomNumberGenerator.h"
#include <utility>

std::set<int> Lottery::draw(const int number_count, const int min, const int max)
{
    std::set<int> lottery_numbers;

    do {
        const int random_number = RandomNumberGenerator::number_between(min, max);
        lottery_numbers.insert(random_number);
    }
    while (lottery_numbers.size() < number_count);

    return std::move(lottery_numbers);
}
