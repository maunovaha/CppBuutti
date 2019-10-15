#include "Vector.h"
#include <string>
#include <valarray>

int Vector::index_of(const char letter, const std::vector<char>& letter_list)
{
    const std::string sentence(letter_list.begin(), letter_list.end());
    const int letter_index = sentence.find(letter);

    return letter_index != std::string::npos ? letter_index : -1;
}

std::vector<char> Vector::shift(const std::vector<char>& letter_list, const int shift_amount)
{
    const std::valarray<char> default_letters{letter_list.data(), letter_list.size()};
    const std::valarray<char> shifted_letters = default_letters.cshift(shift_amount);

    return {std::begin(shifted_letters), std::end(shifted_letters)};
}
