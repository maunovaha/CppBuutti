#include "StringManipulator.h"
#include "Alphabet.h"
#include "Vector.h"
#include <utility>

std::string StringManipulator::to_caesar_chiper(const std::string& value, const int shift_amount)
{
    std::string caesar_chiper = value;

    const std::vector<char> default_alphabet = Alphabet::all_letters();
    const std::vector<char> shifted_alphabet = Vector::shift(default_alphabet, shift_amount);

    for (char& letter : caesar_chiper) {
        int letter_index = Vector::index_of(letter, default_alphabet);
        letter = letter_index != -1 ? shifted_alphabet.at(letter_index) : '?';
    }

    return std::move(caesar_chiper);
}
