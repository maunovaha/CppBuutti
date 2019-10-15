#include "Alphabet.h"
#include <utility>

std::vector<char> Alphabet::all_letters()
{   
    return alphabet_;
}

std::vector<char> Alphabet::between(const char start, const char end)
{
    std::vector<char> letters;

    for (char letter = start; letter <= end; ++letter) {
        letters.emplace_back(letter);
    }

    return std::move(letters);
}
